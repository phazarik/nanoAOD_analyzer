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
    chain->Add("/home/work/alaha1/public/RunII_ULSamples/2018/DYJetsToLL/M50/VLL_DYJetsToLL_M50_98.root");
    hstfilename = "hst_files/hst_2018UL_DYJetsToLL.root";
    sumfilename = "sum_files/sum_dy.txt";
    m_selec.SetData(0); //MC=0, data=1
    m_selec.SetYear(2018);
  }
  //--------------------------------
  //Test on Run2-Legacy (nanoAODv7)
  else if(sample==1){
    chain->Add("/home/work/phazarik1/public/RunII_LegacySamples/2016/VLLS/M100/F5557D8A-DA95-5D4C-91C6-40DBEFDA79E3.root");
    hstfilename = "hst_files/hst_2016_VLLS_tau_M100.root";
    sumfilename = "sum_files/sum_vll.txt";
    m_selec.SetData(0); //MC=0, data=1
    m_selec.SetYear(2016);
  }
  //--------------------------------
  //Test on Run3 (nanoAODv12)
  else if(sample==2){
    chain->Add("/home/work/phazarik1/work/Run3TestSamples/SingleMuon/Run2022B-22Sep2023-v1/*root");
    hstfilename = "hst_files/hst_Summer22_Data.root";
    sumfilename = "sum_files/sum_data.txt";
    m_selec.SetData(1); //MC=0, data=1
    m_selec.SetYear(2016);
  }
  else cout<<"Please choose a correct option!"<<endl;
  
  std::cout<<"Output files are "<<hstfilename<<" and "<<sumfilename<<std::endl;
  // Set some more options.. set the output file names.
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetSumFileName(sumfilename);
  m_selec.SetVerbose(10);//set verbosity level for output.
  // Call the process function which runs the code.
  chain->Process(&m_selec);

}
