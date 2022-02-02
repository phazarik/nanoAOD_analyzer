#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

void ana(int sample=1){
  const char *hstfilename, *sumfilename;
  TChain *chain = new TChain("Events"); //"Events"
  nano9Ana m_selec;
  
  if(sample==0){
    //This is a small file from the UL2016 data.
    chain->Add("inputs/input_data.root");
    hstfilename = "hst_files/hst_data.root";
    sumfilename = "sum_files/sum_data.txt";
    m_selec.SetData(1); //MC=0, data=1
    m_selec.SetYear(2016);
  }
  if(sample==1){
    //process : pp->WZ->3L+nu
    chain->Add("inputs/input_WZ.root");
    hstfilename = "hst_files/hst_WZ.root";
    sumfilename = "sum_files/sum_WZ.txt";
    m_selec.SetData(0); //MC=0, data=1
    m_selec.SetYear(2016);
  }
  if(sample==2){
    //process : pp->ZZ->4L
    chain->Add("inputs/input_ZZ.root");
    hstfilename = "hst_files/hst_ZZ.root";
    sumfilename = "sum_files/sum_ZZ.txt";
    m_selec.SetData(0); //MC=0, data=1
    m_selec.SetYear(2016);
  }
  if(sample==3){
    //process : pp->TTW->2bJets+2L+2nu
    chain->Add("inputs/input_TTW.root");
    hstfilename = "hst_files/hst_TTW.root";
    sumfilename = "sum_files/sum_TTW.txt";
    m_selec.SetData(0); //MC=0, data=1
    m_selec.SetYear(2016);
  }
  
  std::cout<<"Output files are "<<hstfilename<<" and "<<sumfilename<<std::endl;
  // Set some more options.. set the output file names.
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetSumFileName(sumfilename);
  m_selec.SetVerbose(10);//set verbosity level for output.
  // Call the process function which runs the code.
  chain->Process(&m_selec);

}
