#define nanoAna_cxx
// The class definition in nanoAna.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("nanoAna.C")
// root> T->Process("nanoAna.C","some options")
// root> T->Process("nanoAna.C+")
//

#include "nanoAna.h"
#include <TH2.h>
#include <TStyle.h>

//Standard headers:
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

void nanoAna::Begin(TTree * /*tree*/)
{
  // The Begin() function is called at the start of the query.
  // When running with PROOF Begin() is only called on the client.
  // The tree argument is deprecated (on PROOF 0 is passed).
  
  TString option = GetOption();
}

void nanoAna::SlaveBegin(TTree * /*tree*/)
{
  // The SlaveBegin() function is called after the Begin() function.
  // When running with PROOF SlaveBegin() is called on each slave server.
  // The tree argument is deprecated (on PROOF 0 is passed).
  
  TString option = GetOption();
  time(&start);
  
  cout<<"Input parameters:"<<endl;
  cout<<"Data/MC = "<< _data << " (0=MC, 1=Data)" <<endl;
  cout<<"Year = "<<_year<<endl; 
  
  //Initialization of the counters:
  nEvtRan        = 0;
  nEvtTotal      = 0;
  //Other custom counters can be initialized here.

   _HstFile = new TFile(_HstFileName,"recreate");
  BookHistograms();

  // ----------------------------------------------------------------------------------
  // Loading DNNs and scaling parameters:

  // One Environment to rule them all
  ort_env = new Ort::Env(ORT_LOGGING_LEVEL_WARNING, "MultiDNN_Inference");
  Ort::SessionOptions session_options;
  session_options.SetIntraOpNumThreads(1);
    
  // Load model for DY-vs-VLLD:
  TString path_dy = "../trained_models/DY-vs-VLLD_Run3_Feb19/";
  session_dy = new Ort::Session(*ort_env, (path_dy + "model_DY-vs-VLLD_Run3_Feb19.onnx").Data(), session_options);
  scale_min_dy = load_scaling_parameters((path_dy + "scaling_parameters_min.txt").Data());
  scale_max_dy = load_scaling_parameters((path_dy + "scaling_parameters_max.txt").Data());

  // Similarly load other models ...
  
  //-----------------------------------------------------------------------------------
  
  cout<<"\nn-events time(sec)"<<endl;
}

void nanoAna::SlaveTerminate()
{
  // The SlaveTerminate() function is called after all entries or objects
  // have been processed. When running with PROOF SlaveTerminate() is called
  // on each slave server.
  
   _HstFile->Write();
   _HstFile->Close();

  //The following lines are displayed on the root prompt.
   cout<<"----------------------------------------"<<endl;
   cout<<"Total events ran = "<<nEvtRan<<endl;
   cout<<"Total good events = "<<nEvtTotal<<endl;

  //The following lines are written on the sum_<process name>.txt file
  ofstream fout(_SumFileName);
  fout<<"Total events ran = "<<nEvtRan<<endl;
  fout<<"Total good events  = "<<nEvtTotal<<endl;

  time(&end);
  double time_taken = double(end-start);
  cout<<"\nTime taken by the programe is = "<<fixed<<time_taken<<setprecision(5);
  cout<<" sec \n"<<endl;
}

void nanoAna::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file. 
}

Bool_t nanoAna::Process(Long64_t entry)
{
  nEvtTotal++;   //Total number of events in the file

  // The Process() function is called for each entry in the tree (or possibly
  // keyed object in the case of PROOF) to be processed. The entry argument
  // specifies which entry in the currently loaded tree is to be processed.
  // When processing keyed objects with PROOF, the object is already loaded
  // and is available via the fObject pointer.
  //
  // This function should contain the \"body\" of the analysis. It can contain
  // simple or elaborate selection criteria, run algorithms on the data
  // of the event and typically fill histograms.
  //
  // The processing can be stopped by calling Abort().
  //
  // Use fStatus to set the return value of TTree::Process().
  //
  // The return value is currently not used.
  
  //------------------------------------------------------
  //Initializing fReaders:
  fReader.SetLocalEntry(entry);
  if(_run3)  fReader_Run3.SetLocalEntry(entry);
  else       fReader_Run2.SetLocalEntry(entry);
  if(_data == 0){
    fReader_MC.SetLocalEntry(entry);
    if(!_run3) fReader_Run2_MC.SetLocalEntry(entry);
    else       fReader_Run3_MC.SetLocalEntry(entry);
  }
  //------------------------------------------------------

  //Setting verbosity:
  time(&buffer);
  double time_buff = double(buffer-start);
  if (nEvtTotal % _verbosity == 0) cout << setw(10) << left << nEvtTotal << " " << (int)time_buff << endl;
  
  //The following flags throws away some trash events
  GoodEvt2018 = (_year==2018 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && *Flag_BadPFMuonFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  GoodEvt2017 = (_year==2017 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && *Flag_BadPFMuonFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  GoodEvt2016 = (_year==2016 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && *Flag_BadPFMuonFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  
  GoodEvt = GoodEvt2018 && GoodEvt2017 && GoodEvt2016;
  
  if(GoodEvt){

    nEvtRan++;  //Total number of good events
 
                                         //The analysis is done for these good events.


    //Construction of the arrays:
    
    //Reco Muon array :
    int nmu = 0;                         // This counts the number of muons in each event.
    RecoMu.clear();                      // Make sure that the array is empty before filling it up.
    for(int i=0; i<(int)*nMuon; i++){
                                         // This loop runs over all the muon candidates. Some of them will pass our selection criteria.
                                         // These will be stored in the RecoMu array.
      Lepton temp;                       // 'temp' is the i-th candidate.
      temp.v.SetPtEtaPhiM(Muon_pt[i],Muon_eta[i],Muon_phi[i],0.105);
      temp.charge = Muon_charge[i];
      temp.id = -13*Muon_charge[i];      //pdgID for mu- = 13, pdgID for mu+ = -13  
      temp.ind = i;

      //These are the flags the 'temp' object has to pass.
      bool passCuts = temp.v.Pt()>15 && fabs(temp.v.Eta())<2.4 && Muon_mediumId[i];
      passCuts = passCuts && Muon_pfRelIso04_all[i]<0.15;
      passCuts = passCuts && fabs(Muon_dxy[i])<0.05 && fabs(Muon_dz[i])<0.1;
      
      if(passCuts){
	RecoMu.push_back(temp);          // If 'temp' satisfies all the conditions, it is pushed back into RecoMu
	nmu++;                           // Everytime a 'temp' passes the flags, this counter increases by one.
      }
    }                                    // This 'for' loop has created a RecoMu array.
    
    SortPt(0);                           //The RecoMu array has been organised in the decreasing order of pT.


    //Reco jets:
    int njet = 0;
    RecoJet.clear();
    for(int i=0; i<(int)*nJet; i++){
      Lepton temp;
      temp.v.SetPtEtaPhiM(Jet_pt[i], Jet_eta[i], Jet_phi[i], Jet_mass[i]);

      temp.ind = i;
      bool passCuts = temp.v.Pt()>50 && fabs(temp.v.Eta())<2.4 && (int)Jet_jetId[i]>=2;
      if(passCuts){
	RecoJet.push_back(temp);
	njet++;
      }
    }
    SortPt(1);
    
    //Other arrays, such as RecoEle, GenMu, GenEle can be constructed here.











    
    //##############
    // Analysis
    //##############

    //Plotting the leading muon pT in each event.
    if((int)RecoMu.size()>0){             //If there is atleast one muon in the event
      h.hist[0] -> Fill(RecoMu.at(0).v.Pt());
    }
    
    //Plotting a variable that was kept in a pointer (because of different name across Run2/Run3)
    //------------------------------------  Note  -----------------------------------------
    //ptr_fixedGridRhoFastjetAll is a pointer to a TTreeReaderValue<Float_t>.
    //*ptr_fixedGridRhoFastjetAll gives you the TTreeReaderValue<Float_t> object.
    //**ptr_fixedGridRhoFastjetAll gives you the actual float value stored in that object.
    //-------------------------------------------------------------------------------------
    h.hist[1]->Fill(**ptr_fixedGridRhoFastjetAll);



    // --------------- DNN section -----------------
    // The example model is trained to classify VLL against DY in 2L phase space.
    // It requires input variables that are defined in 2L events.
    // In this example, we will strick to exclusively 2-mu events.
    //
    // Files needed:
    //  - model_DY-vs-VLLD_Run3_Feb19.onnx
    //  - scaling_parameters_min.txt
    //  - scaling_parameters_max.txt
    //
    // input variables (in order): dilep_dphi, dilep_eta, dilep_ptratio, HT, LT, metpt

    float score_dy = -99; //dummy value to keep the invalid events
    
    if((int)RecoMu.size()==2){ //Pick the right phase space.
      
      // Prepare the training variables and create arrays for the DNNs.
      float dilep_dphi = delta_phi(RecoMu.at(0).v.Phi(), RecoMu.at(1).v.Phi());
      float dilep_eta = (RecoMu.at(0).v + RecoMu.at(1).v).Eta();
      float dilep_ptratio = RecoMu.at(1).v.Pt()/RecoMu.at(0).v.Pt();
      float HT = 0; for(int i=0; i<(int)RecoJet.size(); i++) HT += RecoJet.at(i).v.Pt();
      float LT = RecoMu.at(0).v.Pt() + RecoMu.at(1).v.Pt();
      float metpt = *PuppiMET_pt;

      // Evaluate score 1:
      std::vector<float> invar_dy = {dilep_dphi, dilep_eta, dilep_ptratio, HT, LT, metpt};
      score_dy = evaluateDNN(session_dy, invar_dy, scale_min_dy, scale_max_dy, "input", "keras_tensor_3");

      // Note: The input and output node names ("input", "keras_tensor_3") are
      // specific to how this model was saved. Verify this via https://netron.app/.

      // Similarly evaluate for other scores.

    }
    
    h.hist[2]->Fill(score_dy); // Includes dummy values as well.
    // ---------------------------------------------
    
    //########### ANALYSIS ENDS HERE ##############
  }//GoodEvt

  
  return kTRUE;
}


//######################################
//        USER DEFINED FUNCTIONS
//######################################
void nanoAna::SortPt(int opt)
{
  //This functions sorts an array in the decreasing order of pT.
  //For recoMu:
  if(opt==0){
    for(int i=0; i<(int)RecoMu.size()-1; i++){
      for(int j=i+1; j<(int)RecoMu.size(); j++){
	if( RecoMu[i].v.Pt() < RecoMu[j].v.Pt() ) swap(RecoMu.at(i),RecoMu.at(j));
      }}}
  if(opt==1){
    for(int i=0; i<(int)RecoJet.size()-1; i++){
      for(int j=i+1; j<(int)RecoJet.size(); j++){
	if( RecoJet[i].v.Pt() < RecoJet[j].v.Pt() ) swap(RecoJet.at(i),RecoJet.at(j));
      }}}
  //Repeat this for the other arrays here.
}

int nanoAna::GenMother(int ind, int mom_ind)
{
  int p_id = GenPart_pdgId[ind];
  int m_id = GenPart_pdgId[mom_ind];
  while(p_id==m_id){
    ind = mom_ind;
    mom_ind = GenPart_genPartIdxMother[ind];
    p_id = GenPart_pdgId[ind];
    m_id = GenPart_pdgId[mom_ind];
  }
  return m_id;
}

float nanoAna::delta_phi(float phi1, float phi2)
{
  //The correct deltaPhi falls in the interval [0 , pi]
  phi1 = TVector2::Phi_0_2pi(phi1);
  phi2 = TVector2::Phi_0_2pi(phi2);
  float dphi = fabs(phi1 - phi2);
  if(dphi>TMath::Pi()) dphi = 2*TMath::Pi() - dphi;
  return dphi;
}

float nanoAna::transv_mass(float E_lep, float MET, float dphi)
{
  //The inputs are the Energy of the lepton, MET and dPhi between the lepton and MET
  float mT = sqrt(2* E_lep * MET *(1-cos(dphi)));
  return mT;
}

void nanoAna::BookHistograms()
{
  //The histograms are booked here.
  //Binning etc are done here.
  //These histograms are stored in the hst_<process name>.root file in the same order.
  
  h.hist[0] = new TH1F("leading_muon_pT", "leading muon pT", 200, 0, 200);
  h.hist[1] = new TH1F("ptr_fixedGridRhoFastjetAll", "ptr_fixedGridRhoFastjetAll", 200, 0, 200);
  h.hist[2] = new TH1F("dnn_score_1", "dnn_score_1", 100, 0, 1);
  //Example : new TH1F ("hst_name", "hst title", total bins, initial x, final x);
  
}

// DNN specific functions:
vector<float> nanoAna::load_scaling_parameters(const char* filename) 
{
  vector<float> params;
  ifstream file(filename);    
  if (!file.is_open()) {
    cerr << "ERROR: Could not open scaling parameter file: " << filename << endl;
    return params;
  }
  float val;
  while(file >> val)  params.push_back(val);
  file.close();
  return params;
}
float nanoAna::evaluateDNN(Ort::Session* session, 
                  std::vector<float> input_vars, 
                  const std::vector<float>& scale_min, 
                  const std::vector<float>& scale_max,
                  const char* input_name,
                  const char* output_name)
{
  int debug_evt = 500;
  if(nEvtTotal==debug_evt) cout << "[DEBUG] test event: "<<debug_evt<<endl;

  // 1. Normalize data between [-1, 1] (same as training)
  for(size_t i = 0; i < input_vars.size(); i++) {
    float raw = input_vars[i];
    float diff = scale_max[i] - scale_min[i];
    if(diff != 0) input_vars[i] = 2.0 * ((raw - scale_min[i]) / diff) - 1.0;
    else          input_vars[i] = 0.0; // Handle constant features
    if(nEvtTotal == debug_evt)
      cout << "[DEBUG] Feature " << i << ": Raw=" << raw << " | Scaled=" << input_vars[i] << endl;
  }
      
  // 2. Setup memory and define tensor shape: [batch_size, number_of_features]
  Ort::MemoryInfo memory_info = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);
  std::vector<int64_t> input_shape = {1, static_cast<int64_t>(input_vars.size())}; 

  // 3. Convert the C++ vector into an ONNX tensor object
  Ort::Value input_tensor = Ort::Value::CreateTensor<float>(
							    memory_info,         // CPU memory allocation
							    input_vars.data(),   // Pointer to scaled float data
							    input_vars.size(),   // Total number of data points
							    input_shape.data(),  // Pointer to the shape array
							    input_shape.size()); // Number of dimensions (2)

  // 4. Define the exact node names baked into the ONNX model
  const char* input_names[]  = {input_name};  // Where the data goes in
  const char* output_names[] = {output_name}; // Where the prediction comes out

  // 5. Fire the inference engine
  auto output_tensors = session->Run(
				     Ort::RunOptions{nullptr}, // Default run options
				     input_names,              // Target input layer, depends on the model type
				     &input_tensor,            // Our formatted data
				     1,                        // Number of input tensors being passed
				     output_names,             // Target output layer, depends on the model type
				     1);                       // Number of output tensors are expected back

  // 6. Extract the raw prediction score and return it
  float* floatarr = output_tensors.front().GetTensorMutableData<float>();
  float final_score = floatarr[0];
  if(nEvtTotal==debug_evt) cout << "[DEBUG] >>> Model Output Score: " << final_score << endl;
  return final_score;
}
