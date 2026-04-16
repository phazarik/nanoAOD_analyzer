#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
using namespace std;

void ana(int sample=0){

  gErrorIgnoreLevel = kError;  // Suppress warnings below 'Error' level
  
  const char *hstfilename, *sumfilename;
  TChain *chain = new TChain("Events"); //"Events"
  nanoAna m_selec;

  //--------------------------------
  // Test on Run2-UltraLegacy (nanoAODv9)
  if(sample==0){
    chain->Add("inputs/testfile_Run3Summer22EE_2L.root");
    hstfilename = "hst_files/hst_testfile_Run3Summer22EE_2L.root";
    sumfilename = "sum_files/sum_testfile_Run3Summer22EE_2L.txt";
    m_selec.SetData(0); //MC=0, data=1
    m_selec.SetYear(2022);
  }
  //--------------------------------
  else cout<<"Please choose a correct option!"<<endl;

  //Printing out some debug statements:
  if(chain->GetListOfFiles()->GetEntries() == 0){
    cout << "ERROR: No input files found or they could not be opened!" << endl;
    return;
  }
  cout << "\n\033[33mThe following input file(s) are loaded successfully:\033[0m" << endl;
  for (int i = 0; i < chain->GetListOfFiles()->GetEntries(); i++)
    cout << "  - " << chain->GetListOfFiles()->At(i)->GetTitle() << endl;
 
  cout<<"\n\033[33mThe following output files are being created:\033[0m"<<endl;
  cout<<"Histogram file: "<<hstfilename<<endl;
  cout<<"Text file: "<<sumfilename<<endl;

  // Set the remaining parameters to the event processor:
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetSumFileName(sumfilename);
  m_selec.SetVerbose(1000); //After how many events do you want a report?
  
  // Call the process function which runs the code.
  cout<<"\n\033[93mRunning the event processor ... \033[0m\n";
  chain->Process(&m_selec);
  cout<<"\nDone!"<<endl;

}
