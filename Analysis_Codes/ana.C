#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

void ana(int sample=1){
  const char *hstfilename, *sumfilename;
  TChain *chain = new TChain("Events"); //"Events"
  nanoAna m_selec;

  //--------------------------------
  // Test on Run2-UltraLegacy (nanoAODv9)
  if(sample==0){
    chain->Add("inputs/testfile_Run3Summer22.root");
    hstfilename = "hst_files/hst_testfile_Run3Summer22.root";
    sumfilename = "sum_files/sum_testfile_Run3Summer22.txt";
    m_selec.SetData(0); //MC=0, data=1
    m_selec.SetYear(2018);
  }
  //--------------------------------
  else cout<<"Please choose a correct option!"<<endl;
  
  std::cout<<"Output files are "<<hstfilename<<" and "<<sumfilename<<std::endl;
  // Set some more options.. set the output file names.
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetSumFileName(sumfilename);
  m_selec.SetVerbose(10);//set verbosity level for output.
  // Call the process function which runs the code.
  chain->Process(&m_selec);

}
