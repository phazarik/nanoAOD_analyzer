////////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Feb  2 10:51:23 2022 by ROOT version 6.22/07
// from TTree Events/Events
// found on file: WZ_UL_2016_MC.root (an MC file for UL2016)
////////////////////////////////////////////////////////////

#ifndef nanoAna_h
#define nanoAna_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include <vector>
#include <TH1.h>
#include <TH2.h>
#include <TMath.h>
#include "TLorentzVector.h"
#include <fstream>
#include <iostream>
#include "TString.h"
#include <bitset>

class nanoAna : public TSelector {

public:
  bool _run3; //Initialize it in the Init() method. Default = False.

private:  

  // Run2 and Run3 filesh have different data types.
  // I am using my own customized types as follows.
  // Uncomment the section that you need.
  // Set the booelan _run3 accordingly.
  
  //for Run3:
  /*
    using iterator     = Int_t;
    using int_or_char  = UChar_t;
    using int_or_short = Short_t;
    using int_or_ushort = UShort_t;*/

  //for Run2
  using iterator     = UInt_t; 
  using int_or_char  = Int_t;
  using int_or_short = Int_t;
  using int_or_ushort = Int_t; 


public :
  TTreeReader     fReader;
  TTreeReader     fReader_Run2;
  TTreeReader     fReader_Run3;
  TTreeReader     fReader_MC;
  TTreeReader     fReader_Run2_MC;
  TTreeReader     fReader_Run3_MC;

  TTree          *fChain = 0;    //!pointer to the analyzed TTree or TChain
  
  // Readers to access the data (delete the ones you do not need).
  // Unnecessary branches can be commented out.
  
  //#####################################################
  // The following Common branches are read with fReader
  //#####################################################
  TTreeReaderValue<UInt_t> run = {fReader, "run"};
  TTreeReaderValue<UInt_t> luminosityBlock = {fReader, "luminosityBlock"};
  TTreeReaderValue<ULong64_t> event = {fReader, "event"};
  
  //Electrons
  TTreeReaderValue<iterator> nElectron = {fReader, "nElectron"};
  TTreeReaderArray<Float_t> Electron_deltaEtaSC = {fReader, "Electron_deltaEtaSC"};
  TTreeReaderArray<Float_t> Electron_dr03EcalRecHitSumEt = {fReader, "Electron_dr03EcalRecHitSumEt"};
  TTreeReaderArray<Float_t> Electron_dr03HcalDepth1TowerSumEt = {fReader, "Electron_dr03HcalDepth1TowerSumEt"};
  TTreeReaderArray<Float_t> Electron_dr03TkSumPt = {fReader, "Electron_dr03TkSumPt"};
  TTreeReaderArray<Float_t> Electron_dr03TkSumPtHEEP = {fReader, "Electron_dr03TkSumPtHEEP"};
  TTreeReaderArray<Float_t> Electron_dxy = {fReader, "Electron_dxy"};
  TTreeReaderArray<Float_t> Electron_dxyErr = {fReader, "Electron_dxyErr"};
  TTreeReaderArray<Float_t> Electron_dz = {fReader, "Electron_dz"};
  TTreeReaderArray<Float_t> Electron_dzErr = {fReader, "Electron_dzErr"};
  TTreeReaderArray<Float_t> Electron_eInvMinusPInv = {fReader, "Electron_eInvMinusPInv"};
  TTreeReaderArray<Float_t> Electron_energyErr = {fReader, "Electron_energyErr"};
  TTreeReaderArray<Float_t> Electron_eta = {fReader, "Electron_eta"};
  TTreeReaderArray<Float_t> Electron_hoe = {fReader, "Electron_hoe"};
  TTreeReaderArray<Float_t> Electron_ip3d = {fReader, "Electron_ip3d"};
  TTreeReaderArray<Float_t> Electron_jetPtRelv2 = {fReader, "Electron_jetPtRelv2"};
  TTreeReaderArray<Float_t> Electron_jetRelIso = {fReader, "Electron_jetRelIso"};
  TTreeReaderArray<Float_t> Electron_mass = {fReader, "Electron_mass"};
  TTreeReaderArray<Float_t> Electron_miniPFRelIso_all = {fReader, "Electron_miniPFRelIso_all"};
  TTreeReaderArray<Float_t> Electron_miniPFRelIso_chg = {fReader, "Electron_miniPFRelIso_chg"};
  TTreeReaderArray<Float_t> Electron_pfRelIso03_all = {fReader, "Electron_pfRelIso03_all"};
  TTreeReaderArray<Float_t> Electron_pfRelIso03_chg = {fReader, "Electron_pfRelIso03_chg"};
  TTreeReaderArray<Float_t> Electron_phi = {fReader, "Electron_phi"};
  TTreeReaderArray<Float_t> Electron_pt = {fReader, "Electron_pt"};
  TTreeReaderArray<Float_t> Electron_r9 = {fReader, "Electron_r9"};
  TTreeReaderArray<Float_t> Electron_scEtOverPt = {fReader, "Electron_scEtOverPt"};
  TTreeReaderArray<Float_t> Electron_sieie = {fReader, "Electron_sieie"};
  TTreeReaderArray<Float_t> Electron_sip3d = {fReader, "Electron_sip3d"};
  TTreeReaderArray<Float_t> Electron_mvaTTH = {fReader, "Electron_mvaTTH"};
  TTreeReaderArray<Int_t> Electron_charge = {fReader, "Electron_charge"};
  TTreeReaderArray<int_or_char> Electron_cutBased = {fReader, "Electron_cutBased"};
  TTreeReaderArray<int_or_short> Electron_jetIdx = {fReader, "Electron_jetIdx"};
  TTreeReaderArray<Int_t> Electron_pdgId = {fReader, "Electron_pdgId"};
  TTreeReaderArray<int_or_short> Electron_photonIdx = {fReader, "Electron_photonIdx"};
  TTreeReaderArray<int_or_char> Electron_tightCharge = {fReader, "Electron_tightCharge"};
  TTreeReaderArray<Int_t> Electron_vidNestedWPBitmap = {fReader, "Electron_vidNestedWPBitmap"};
  TTreeReaderArray<Int_t> Electron_vidNestedWPBitmapHEEP = {fReader, "Electron_vidNestedWPBitmapHEEP"};
  TTreeReaderArray<Bool_t> Electron_convVeto = {fReader, "Electron_convVeto"};
  TTreeReaderArray<Bool_t> Electron_cutBased_HEEP = {fReader, "Electron_cutBased_HEEP"};
  TTreeReaderArray<Bool_t> Electron_isPFcand = {fReader, "Electron_isPFcand"};
  TTreeReaderArray<UChar_t> Electron_seedGain = {fReader, "Electron_seedGain"};

  /*
  //IsoTrack
  TTreeReaderValue<iterator> nIsoTrack = {fReader, "nIsoTrack"};
  TTreeReaderArray<Float_t> IsoTrack_dxy = {fReader, "IsoTrack_dxy"};
  TTreeReaderArray<Float_t> IsoTrack_dz = {fReader, "IsoTrack_dz"};
  TTreeReaderArray<Float_t> IsoTrack_eta = {fReader, "IsoTrack_eta"};
  TTreeReaderArray<Float_t> IsoTrack_pfRelIso03_all = {fReader, "IsoTrack_pfRelIso03_all"};
  TTreeReaderArray<Float_t> IsoTrack_pfRelIso03_chg = {fReader, "IsoTrack_pfRelIso03_chg"};
  TTreeReaderArray<Float_t> IsoTrack_phi = {fReader, "IsoTrack_phi"};
  TTreeReaderArray<Float_t> IsoTrack_pt = {fReader, "IsoTrack_pt"};
  TTreeReaderArray<Float_t> IsoTrack_miniPFRelIso_all = {fReader, "IsoTrack_miniPFRelIso_all"};
  TTreeReaderArray<Float_t> IsoTrack_miniPFRelIso_chg = {fReader, "IsoTrack_miniPFRelIso_chg"};
  TTreeReaderArray<int_to_short>   IsoTrack_charge = {fReader, "IsoTrack_charge"};
  TTreeReaderArray<Int_t>   IsoTrack_fromPV = {fReader, "IsoTrack_fromPV"};
  TTreeReaderArray<Int_t>   IsoTrack_pdgId = {fReader, "IsoTrack_pdgId"};
  TTreeReaderArray<Bool_t>  IsoTrack_isHighPurityTrack = {fReader, "IsoTrack_isHighPurityTrack"};
  TTreeReaderArray<Bool_t>  IsoTrack_isPFcand = {fReader, "IsoTrack_isPFcand"};
  TTreeReaderArray<Bool_t>  IsoTrack_isFromLostTrack = {fReader, "IsoTrack_isFromLostTrack"};*/
  
  //Jet
  TTreeReaderValue<iterator> nJet = {fReader, "nJet"};
  TTreeReaderArray<Float_t> Jet_area = {fReader, "Jet_area"};
  TTreeReaderArray<Float_t> Jet_btagDeepFlavB = {fReader, "Jet_btagDeepFlavB"};
  TTreeReaderArray<Float_t> Jet_chEmEF = {fReader, "Jet_chEmEF"};
  TTreeReaderArray<Float_t> Jet_chHEF = {fReader, "Jet_chHEF"};
  TTreeReaderArray<Float_t> Jet_eta = {fReader, "Jet_eta"};
  TTreeReaderArray<Float_t> Jet_mass = {fReader, "Jet_mass"};
  TTreeReaderArray<Float_t> Jet_muEF = {fReader, "Jet_muEF"};
  TTreeReaderArray<Float_t> Jet_muonSubtrFactor = {fReader, "Jet_muonSubtrFactor"};
  TTreeReaderArray<Float_t> Jet_neEmEF = {fReader, "Jet_neEmEF"};
  TTreeReaderArray<Float_t> Jet_neHEF = {fReader, "Jet_neHEF"};
  TTreeReaderArray<Float_t> Jet_phi = {fReader, "Jet_phi"};
  TTreeReaderArray<Float_t> Jet_pt = {fReader, "Jet_pt"};
  TTreeReaderArray<int_or_short>   Jet_electronIdx1 = {fReader, "Jet_electronIdx1"};
  TTreeReaderArray<int_or_short>   Jet_electronIdx2 = {fReader, "Jet_electronIdx2"};
  TTreeReaderArray<int_or_char>   Jet_jetId = {fReader, "Jet_jetId"};
  TTreeReaderArray<int_or_short>   Jet_muonIdx1 = {fReader, "Jet_muonIdx1"};
  TTreeReaderArray<int_or_short>   Jet_muonIdx2 = {fReader, "Jet_muonIdx2"};
  TTreeReaderArray<int_or_char>   Jet_nElectrons = {fReader, "Jet_nElectrons"};
  TTreeReaderArray<int_or_char>   Jet_nMuons = {fReader, "Jet_nMuons"};

  //MET
  TTreeReaderValue<Float_t> MET_MetUnclustEnUpDeltaX = {fReader, "MET_MetUnclustEnUpDeltaX"};
  TTreeReaderValue<Float_t> MET_MetUnclustEnUpDeltaY = {fReader, "MET_MetUnclustEnUpDeltaY"};
  TTreeReaderValue<Float_t> MET_covXX =                {fReader, "MET_covXX"};
  TTreeReaderValue<Float_t> MET_covXY =                {fReader, "MET_covXY"};
  TTreeReaderValue<Float_t> MET_covYY =                {fReader, "MET_covYY"};
  TTreeReaderValue<Float_t> MET_phi =                  {fReader, "MET_phi"};
  TTreeReaderValue<Float_t> MET_pt =                   {fReader, "MET_pt"};
  TTreeReaderValue<Float_t> MET_significance =         {fReader, "MET_significance"};
  TTreeReaderValue<Float_t> MET_sumEt =                {fReader, "MET_sumEt"};
  TTreeReaderValue<Float_t> MET_sumPtUnclustered =     {fReader, "MET_sumPtUnclustered"};

  //Muons
  TTreeReaderValue<iterator> nMuon = {fReader, "nMuon"};
  TTreeReaderArray<Float_t> Muon_dxy = {fReader, "Muon_dxy"};
  TTreeReaderArray<Float_t> Muon_dxyErr = {fReader, "Muon_dxyErr"};
  TTreeReaderArray<Float_t> Muon_dxybs = {fReader, "Muon_dxybs"};
  TTreeReaderArray<Float_t> Muon_dz = {fReader, "Muon_dz"};
  TTreeReaderArray<Float_t> Muon_dzErr = {fReader, "Muon_dzErr"};
  TTreeReaderArray<Float_t> Muon_eta = {fReader, "Muon_eta"};
  TTreeReaderArray<Float_t> Muon_ip3d = {fReader, "Muon_ip3d"};
  TTreeReaderArray<Float_t> Muon_jetPtRelv2 = {fReader, "Muon_jetPtRelv2"};
  TTreeReaderArray<Float_t> Muon_jetRelIso = {fReader, "Muon_jetRelIso"};
  TTreeReaderArray<Float_t> Muon_mass = {fReader, "Muon_mass"};
  TTreeReaderArray<Float_t> Muon_miniPFRelIso_all = {fReader, "Muon_miniPFRelIso_all"};
  TTreeReaderArray<Float_t> Muon_miniPFRelIso_chg = {fReader, "Muon_miniPFRelIso_chg"};
  TTreeReaderArray<Float_t> Muon_pfRelIso03_all = {fReader, "Muon_pfRelIso03_all"};
  TTreeReaderArray<Float_t> Muon_pfRelIso03_chg = {fReader, "Muon_pfRelIso03_chg"};
  TTreeReaderArray<Float_t> Muon_pfRelIso04_all = {fReader, "Muon_pfRelIso04_all"};
  TTreeReaderArray<Float_t> Muon_phi = {fReader, "Muon_phi"};
  TTreeReaderArray<Float_t> Muon_pt = {fReader, "Muon_pt"};
  TTreeReaderArray<Float_t> Muon_ptErr = {fReader, "Muon_ptErr"};
  TTreeReaderArray<Float_t> Muon_segmentComp = {fReader, "Muon_segmentComp"};
  TTreeReaderArray<Float_t> Muon_sip3d = {fReader, "Muon_sip3d"};
  TTreeReaderArray<Float_t> Muon_tkRelIso = {fReader, "Muon_tkRelIso"};
  TTreeReaderArray<Float_t> Muon_tunepRelPt = {fReader, "Muon_tunepRelPt"};
  TTreeReaderArray<Float_t> Muon_mvaLowPt = {fReader, "Muon_mvaLowPt"};
  TTreeReaderArray<Float_t> Muon_mvaTTH = {fReader, "Muon_mvaTTH"};
  TTreeReaderArray<Int_t>   Muon_charge = {fReader, "Muon_charge"};
  TTreeReaderArray<int_or_short>   Muon_jetIdx = {fReader, "Muon_jetIdx"};
  TTreeReaderArray<int_or_char>   Muon_nStations = {fReader, "Muon_nStations"};
  TTreeReaderArray<int_or_char>   Muon_nTrackerLayers = {fReader, "Muon_nTrackerLayers"};
  TTreeReaderArray<Int_t>   Muon_pdgId = {fReader, "Muon_pdgId"};
  TTreeReaderArray<int_or_char>   Muon_tightCharge = {fReader, "Muon_tightCharge"};
  TTreeReaderArray<int_or_short>   Muon_fsrPhotonIdx = {fReader, "Muon_fsrPhotonIdx"};
  TTreeReaderArray<UChar_t> Muon_highPtId = {fReader, "Muon_highPtId"};
  TTreeReaderArray<Bool_t>  Muon_highPurity = {fReader, "Muon_highPurity"};
  TTreeReaderArray<Bool_t>  Muon_inTimeMuon = {fReader, "Muon_inTimeMuon"};
  TTreeReaderArray<Bool_t>  Muon_isGlobal = {fReader, "Muon_isGlobal"};
  TTreeReaderArray<Bool_t>  Muon_isPFcand = {fReader, "Muon_isPFcand"};
  TTreeReaderArray<Bool_t>  Muon_isTracker = {fReader, "Muon_isTracker"};
  TTreeReaderArray<Bool_t>  Muon_looseId = {fReader, "Muon_looseId"};
  TTreeReaderArray<Bool_t>  Muon_mediumId = {fReader, "Muon_mediumId"};
  TTreeReaderArray<Bool_t>  Muon_mediumPromptId = {fReader, "Muon_mediumPromptId"};
  TTreeReaderArray<UChar_t> Muon_miniIsoId = {fReader, "Muon_miniIsoId"};
  TTreeReaderArray<UChar_t> Muon_multiIsoId = {fReader, "Muon_multiIsoId"};
  TTreeReaderArray<UChar_t> Muon_pfIsoId = {fReader, "Muon_pfIsoId"};
  TTreeReaderArray<Bool_t>  Muon_softId = {fReader, "Muon_softId"};
  TTreeReaderArray<Bool_t>  Muon_softMvaId = {fReader, "Muon_softMvaId"};
  TTreeReaderArray<Bool_t>  Muon_tightId = {fReader, "Muon_tightId"};
  TTreeReaderArray<UChar_t> Muon_tkIsoId = {fReader, "Muon_tkIsoId"};
  TTreeReaderArray<Bool_t>  Muon_triggerIdLoose = {fReader, "Muon_triggerIdLoose"};

  //Photon
  TTreeReaderValue<iterator> nPhoton =            {fReader, "nPhoton"};
  TTreeReaderArray<Float_t> Photon_energyErr =   {fReader, "Photon_energyErr"};
  TTreeReaderArray<Float_t> Photon_eta =         {fReader, "Photon_eta"};
  TTreeReaderArray<Float_t> Photon_hoe =         {fReader, "Photon_hoe"};
  TTreeReaderArray<Float_t> Photon_mvaID =       {fReader, "Photon_mvaID"};
  TTreeReaderArray<Float_t> Photon_phi =         {fReader, "Photon_phi"};
  TTreeReaderArray<Float_t> Photon_pt =          {fReader, "Photon_pt"};
  TTreeReaderArray<Float_t> Photon_r9 =          {fReader, "Photon_r9"};
  TTreeReaderArray<Float_t> Photon_sieie =       {fReader, "Photon_sieie"};
  TTreeReaderArray<int_or_char>  Photon_cutBased =    {fReader, "Photon_cutBased"};
  TTreeReaderArray<int_or_short>  Photon_electronIdx = {fReader, "Photon_electronIdx"};
  TTreeReaderArray<int_or_short>  Photon_jetIdx =      {fReader, "Photon_jetIdx"};
  TTreeReaderArray<Int_t>   Photon_vidNestedWPBitmap = {fReader, "Photon_vidNestedWPBitmap"};
  TTreeReaderArray<Bool_t>  Photon_electronVeto ={fReader, "Photon_electronVeto"};
  TTreeReaderArray<Bool_t>  Photon_isScEtaEB =   {fReader, "Photon_isScEtaEB"};
  TTreeReaderArray<Bool_t>  Photon_isScEtaEE =   {fReader, "Photon_isScEtaEE"};
  TTreeReaderArray<Bool_t>  Photon_mvaID_WP80 =  {fReader, "Photon_mvaID_WP80"};
  TTreeReaderArray<Bool_t>  Photon_mvaID_WP90 =  {fReader, "Photon_mvaID_WP90"};
  TTreeReaderArray<Bool_t>  Photon_pixelSeed =   {fReader, "Photon_pixelSeed"};
  TTreeReaderArray<UChar_t> Photon_seedGain =    {fReader, "Photon_seedGain"};

  //PuppiMET
  TTreeReaderValue<Float_t> PuppiMET_phi =                {fReader, "PuppiMET_phi"};
  TTreeReaderValue<Float_t> PuppiMET_phiJERUp =           {fReader, "PuppiMET_phiJERUp"};
  TTreeReaderValue<Float_t> PuppiMET_phiJESUp =           {fReader, "PuppiMET_phiJESUp"};
  TTreeReaderValue<Float_t> PuppiMET_pt =                 {fReader, "PuppiMET_pt"};
  TTreeReaderValue<Float_t> PuppiMET_ptJERUp =            {fReader, "PuppiMET_ptJERUp"};
  TTreeReaderValue<Float_t> PuppiMET_ptJESUp =            {fReader, "PuppiMET_ptJESUp"};
  TTreeReaderValue<Float_t> PuppiMET_sumEt =              {fReader, "PuppiMET_sumEt"};

  //Tau
  TTreeReaderValue<iterator> nTau = {fReader, "nTau"};
  TTreeReaderArray<Float_t> Tau_chargedIso = {fReader, "Tau_chargedIso"};
  TTreeReaderArray<Float_t> Tau_dxy = {fReader, "Tau_dxy"};
  TTreeReaderArray<Float_t> Tau_dz = {fReader, "Tau_dz"};
  TTreeReaderArray<Float_t> Tau_eta = {fReader, "Tau_eta"};
  TTreeReaderArray<Float_t> Tau_leadTkDeltaEta = {fReader, "Tau_leadTkDeltaEta"};
  TTreeReaderArray<Float_t> Tau_leadTkDeltaPhi = {fReader, "Tau_leadTkDeltaPhi"};
  TTreeReaderArray<Float_t> Tau_leadTkPtOverTauPt = {fReader, "Tau_leadTkPtOverTauPt"};
  TTreeReaderArray<Float_t> Tau_mass = {fReader, "Tau_mass"};
  TTreeReaderArray<Float_t> Tau_neutralIso = {fReader, "Tau_neutralIso"};
  TTreeReaderArray<Float_t> Tau_phi = {fReader, "Tau_phi"};
  TTreeReaderArray<Float_t> Tau_photonsOutsideSignalCone = {fReader, "Tau_photonsOutsideSignalCone"};
  TTreeReaderArray<Float_t> Tau_pt = {fReader, "Tau_pt"};
  TTreeReaderArray<Float_t> Tau_puCorr = {fReader, "Tau_puCorr"};
  TTreeReaderArray<Float_t> Tau_rawDeepTau2017v2p1VSe = {fReader, "Tau_rawDeepTau2017v2p1VSe"};
  TTreeReaderArray<Float_t> Tau_rawDeepTau2017v2p1VSjet = {fReader, "Tau_rawDeepTau2017v2p1VSjet"};
  TTreeReaderArray<Float_t> Tau_rawDeepTau2017v2p1VSmu = {fReader, "Tau_rawDeepTau2017v2p1VSmu"};
  TTreeReaderArray<Float_t> Tau_rawIso = {fReader, "Tau_rawIso"};
  TTreeReaderArray<Float_t> Tau_rawIsodR03 = {fReader, "Tau_rawIsodR03"};
  TTreeReaderArray<int_or_short> Tau_charge = {fReader, "Tau_charge"};
  TTreeReaderArray<int_or_char>  Tau_decayMode = {fReader, "Tau_decayMode"};
  TTreeReaderArray<int_or_short> Tau_jetIdx = {fReader, "Tau_jetIdx"};
  TTreeReaderArray<UChar_t> Tau_idAntiMu = {fReader, "Tau_idAntiMu"};
  TTreeReaderArray<UChar_t> Tau_idDeepTau2017v2p1VSe = {fReader, "Tau_idDeepTau2017v2p1VSe"};
  TTreeReaderArray<UChar_t> Tau_idDeepTau2017v2p1VSjet = {fReader, "Tau_idDeepTau2017v2p1VSjet"};
  TTreeReaderArray<UChar_t> Tau_idDeepTau2017v2p1VSmu = {fReader, "Tau_idDeepTau2017v2p1VSmu"};

  //TrigObj
  TTreeReaderValue<iterator> nTrigObj =           {fReader, "nTrigObj"};
  TTreeReaderArray<Float_t> TrigObj_pt =         {fReader, "TrigObj_pt"};
  TTreeReaderArray<Float_t> TrigObj_eta =        {fReader, "TrigObj_eta"};
  TTreeReaderArray<Float_t> TrigObj_phi =        {fReader, "TrigObj_phi"};
  TTreeReaderArray<Float_t> TrigObj_l1pt =       {fReader, "TrigObj_l1pt"};
  TTreeReaderArray<Float_t> TrigObj_l1pt_2 =     {fReader, "TrigObj_l1pt_2"};
  TTreeReaderArray<Float_t> TrigObj_l2pt =       {fReader, "TrigObj_l2pt"};
  TTreeReaderArray<int_or_ushort>  TrigObj_id =         {fReader, "TrigObj_id"};
  TTreeReaderArray<Int_t>   TrigObj_l1iso =      {fReader, "TrigObj_l1iso"};
  TTreeReaderArray<int_or_short>  TrigObj_l1charge =   {fReader, "TrigObj_l1charge"};
  TTreeReaderArray<Int_t>   TrigObj_filterBits = {fReader, "TrigObj_filterBits"};

  //_______________________________________________________________________
  
  //GenJet (read using fReader_MC)
  TTreeReaderValue<iterator> nGenJet =        {fReader_MC, "nGenJet"};
  TTreeReaderArray<Float_t> GenJet_eta =     {fReader_MC, "GenJet_eta"};
  TTreeReaderArray<Float_t> GenJet_mass =    {fReader_MC, "GenJet_mass"};
  TTreeReaderArray<Float_t> GenJet_phi =     {fReader_MC, "GenJet_phi"};
  TTreeReaderArray<Float_t> GenJet_pt =      {fReader_MC, "GenJet_pt"};
  
  //GenParticles (read using fReader_MC)
  TTreeReaderValue<iterator> nGenPart =                 {fReader_MC, "nGenPart"};
  TTreeReaderArray<Float_t> GenPart_eta =              {fReader_MC, "GenPart_eta"};
  TTreeReaderArray<Float_t> GenPart_mass =             {fReader_MC, "GenPart_mass"};
  TTreeReaderArray<Float_t> GenPart_phi =              {fReader_MC, "GenPart_phi"};
  TTreeReaderArray<Float_t> GenPart_pt =               {fReader_MC, "GenPart_pt"};
  TTreeReaderArray<int_or_short> GenPart_genPartIdxMother = {fReader_MC, "GenPart_genPartIdxMother"};
  TTreeReaderArray<Int_t>   GenPart_pdgId =            {fReader_MC, "GenPart_pdgId"};
  TTreeReaderArray<Int_t>   GenPart_status =           {fReader_MC, "GenPart_status"};
  //TTreeReaderArray<Int_t>   GenPart_statusFlags =      {fReader_MC, "GenPart_statusFlags"};

  //GenVisTau
  TTreeReaderValue<iterator> nGenVisTau =                 {fReader_MC, "nGenVisTau"};
  TTreeReaderArray<Float_t> GenVisTau_eta =              {fReader_MC, "GenVisTau_eta"};
  TTreeReaderArray<Float_t> GenVisTau_mass =             {fReader_MC, "GenVisTau_mass"};
  TTreeReaderArray<Float_t> GenVisTau_phi =              {fReader_MC, "GenVisTau_phi"};
  TTreeReaderArray<Float_t> GenVisTau_pt =               {fReader_MC, "GenVisTau_pt"};
  TTreeReaderArray<Int_t>   GenVisTau_charge =           {fReader_MC, "GenVisTau_charge"};
  TTreeReaderArray<int_or_short> GenVisTau_genPartIdxMother = {fReader_MC, "GenVisTau_genPartIdxMother"};
  TTreeReaderArray<int_or_char>  GenVisTau_status =           {fReader_MC, "GenVisTau_status"};

  //GenMET
  TTreeReaderValue<Float_t> GenMET_phi =         {fReader_MC, "GenMET_phi"};
  TTreeReaderValue<Float_t> GenMET_pt =          {fReader_MC, "GenMET_pt"};

  //Jetflavor:
  TTreeReaderArray<int_or_char> Jet_hadronFlavour = {fReader_MC, "Jet_hadronFlavour"};
  
  //_________________________________________________________________________
  
  //Flags:
  TTreeReaderValue<Bool_t> Flag_HBHENoiseFilter = {fReader, "Flag_HBHENoiseFilter"};
  TTreeReaderValue<Bool_t> Flag_HBHENoiseIsoFilter = {fReader, "Flag_HBHENoiseIsoFilter"};
  TTreeReaderValue<Bool_t> Flag_CSCTightHaloFilter = {fReader, "Flag_CSCTightHaloFilter"};
  TTreeReaderValue<Bool_t> Flag_CSCTightHaloTrkMuUnvetoFilter = {fReader, "Flag_CSCTightHaloTrkMuUnvetoFilter"};
  TTreeReaderValue<Bool_t> Flag_CSCTightHalo2015Filter = {fReader, "Flag_CSCTightHalo2015Filter"};
  TTreeReaderValue<Bool_t> Flag_globalTightHalo2016Filter = {fReader, "Flag_globalTightHalo2016Filter"};
  TTreeReaderValue<Bool_t> Flag_globalSuperTightHalo2016Filter = {fReader, "Flag_globalSuperTightHalo2016Filter"};
  TTreeReaderValue<Bool_t> Flag_HcalStripHaloFilter = {fReader, "Flag_HcalStripHaloFilter"};
  TTreeReaderValue<Bool_t> Flag_hcalLaserEventFilter = {fReader, "Flag_hcalLaserEventFilter"};
  TTreeReaderValue<Bool_t> Flag_EcalDeadCellTriggerPrimitiveFilter = {fReader, "Flag_EcalDeadCellTriggerPrimitiveFilter"};
  TTreeReaderValue<Bool_t> Flag_EcalDeadCellBoundaryEnergyFilter = {fReader, "Flag_EcalDeadCellBoundaryEnergyFilter"};
  TTreeReaderValue<Bool_t> Flag_ecalBadCalibFilter = {fReader, "Flag_ecalBadCalibFilter"};
  TTreeReaderValue<Bool_t> Flag_goodVertices = {fReader, "Flag_goodVertices"};
  TTreeReaderValue<Bool_t> Flag_eeBadScFilter = {fReader, "Flag_eeBadScFilter"};
  TTreeReaderValue<Bool_t> Flag_ecalLaserCorrFilter = {fReader, "Flag_ecalLaserCorrFilter"};
  TTreeReaderValue<Bool_t> Flag_trkPOGFilters = {fReader, "Flag_trkPOGFilters"};
  TTreeReaderValue<Bool_t> Flag_chargedHadronTrackResolutionFilter = {fReader, "Flag_chargedHadronTrackResolutionFilter"};
  TTreeReaderValue<Bool_t> Flag_muonBadTrackFilter = {fReader, "Flag_muonBadTrackFilter"};
  TTreeReaderValue<Bool_t> Flag_BadChargedCandidateFilter = {fReader, "Flag_BadChargedCandidateFilter"};
  TTreeReaderValue<Bool_t> Flag_BadPFMuonFilter = {fReader, "Flag_BadPFMuonFilter"};
  TTreeReaderValue<Bool_t> Flag_BadChargedCandidateSummer16Filter = {fReader, "Flag_BadChargedCandidateSummer16Filter"};
  TTreeReaderValue<Bool_t> Flag_BadPFMuonSummer16Filter = {fReader, "Flag_BadPFMuonSummer16Filter"};
  TTreeReaderValue<Bool_t> Flag_trkPOG_manystripclus53X = {fReader, "Flag_trkPOG_manystripclus53X"};
  TTreeReaderValue<Bool_t> Flag_trkPOG_toomanystripclus53X = {fReader, "Flag_trkPOG_toomanystripclus53X"};
  TTreeReaderValue<Bool_t> Flag_trkPOG_logErrorTooManyClusters = {fReader, "Flag_trkPOG_logErrorTooManyClusters"};
  TTreeReaderValue<Bool_t> Flag_METFilters = {fReader, "Flag_METFilters"};

  //HLT paths that we are intereted in:
  TTreeReaderValue<Bool_t> HLT_IsoMu24 = {fReader, "HLT_IsoMu24"};
  TTreeReaderValue<Bool_t> HLT_IsoMu27 = {fReader, "HLT_IsoMu27"};
  TTreeReaderValue<Bool_t> HLT_Ele27_WPTight_Gsf = {fReader, "HLT_Ele27_WPTight_Gsf"};
  TTreeReaderValue<Bool_t> HLT_Ele32_WPTight_Gsf = {fReader, "HLT_Ele32_WPTight_Gsf"};

  //__________________________________________________________________________________________________________

  //                                  SPECIAL BRANCHES THAT CHANGED NAME
  //----------------------------------------------------------------------------------------------------------
  //Run2 only:
  TTreeReaderValue<Float_t> fixedGridRhoFastjetAll =            {fReader_Run2, "fixedGridRhoFastjetAll"};
  TTreeReaderValue<Float_t> fixedGridRhoFastjetCentral =        {fReader_Run2, "fixedGridRhoFastjetCentral"};
  TTreeReaderValue<Float_t> fixedGridRhoFastjetCentralCalo =    {fReader_Run2, "fixedGridRhoFastjetCentralCalo"};
  TTreeReaderValue<Float_t> fixedGridRhoFastjetCentralChargedPileUp = {fReader_Run2, "fixedGridRhoFastjetCentralChargedPileUp"};
  TTreeReaderValue<Float_t> fixedGridRhoFastjetCentralNeutral = {fReader_Run2, "fixedGridRhoFastjetCentralNeutral"};
  TTreeReaderArray<Float_t> Photon_pfRelIso03_all = {fReader_Run2, "Photon_pfRelIso03_all"};
  TTreeReaderArray<Float_t> Photon_pfRelIso03_chg = {fReader_Run2, "Photon_pfRelIso03_chg"};

  //----------------------------------------------------------------------------------------------------------
  //Run3 only:
  TTreeReaderValue<Float_t> Rho_fixedGridRhoFastjetAll =            {fReader_Run3, "Rho_fixedGridRhoFastjetAll"};
  TTreeReaderValue<Float_t> Rho_fixedGridRhoFastjetCentral =        {fReader_Run3, "Rho_fixedGridRhoFastjetCentral"};
  TTreeReaderValue<Float_t> Rho_fixedGridRhoFastjetCentralCalo =    {fReader_Run3, "Rho_fixedGridRhoFastjetCentralCalo"};
  TTreeReaderValue<Float_t> Rho_fixedGridRhoFastjetCentralChargedPileUp = {fReader_Run3, "Rho_fixedGridRhoFastjetCentralChargedPileUp"};
  TTreeReaderValue<Float_t> Rho_fixedGridRhoFastjetCentralNeutral = {fReader_Run3, "Rho_fixedGridRhoFastjetCentralNeutral"};
  TTreeReaderArray<Float_t> Photon_pfRelIso03_all_quadratic = {fReader_Run3, "Photon_pfRelIso03_all_quadratic"};
  TTreeReaderArray<Float_t> Photon_pfRelIso03_chg_quadratic = {fReader_Run3, "Photon_pfRelIso03_chg_quadratic"};

  //---------------------------------------------------------------------------------------------------------
  // Declare (global) pointers to keep the variables which are of the same type, but different names (e.g. Rho variables). Assign the address of the right TTreeReaderValue (or Array) to the pointers in the Init function.
  //---------------------------------------------------------------------------------------------------------

  TTreeReaderValue<Float_t>* ptr_fixedGridRhoFastjetAll = nullptr;
  TTreeReaderValue<Float_t>* ptr_fixedGridRhoFastjetCentral = nullptr;
  TTreeReaderValue<Float_t>* ptr_fixedGridRhoFastjetCentralCalo = nullptr;
  TTreeReaderValue<Float_t>* ptr_fixedGridRhoFastjetCentralChargedPileUp = nullptr;
  TTreeReaderValue<Float_t>* ptr_fixedGridRhoFastjetCentralNeutral = nullptr;
  TTreeReaderArray<Float_t>* ptr_Photon_pfRelIso03_all = nullptr;
  TTreeReaderArray<Float_t>* ptr_Photon_pfRelIso03_chg = nullptr;
  
  //__________________________________________________________________________________________________________
  //__________________________________________________________________________________________________________
  
  nanoAna(TTree * /*tree*/ =0) { }
  virtual ~nanoAna() { }
  virtual Int_t   Version() const { return 2; }
  virtual void    Begin(TTree *tree);
  virtual void    SlaveBegin(TTree *tree);
  virtual void    Init(TTree *tree);
  virtual Bool_t  Notify();
  virtual Bool_t  Process(Long64_t entry);
  virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
  virtual void    SetOption(const char *option) { fOption = option; }
  virtual void    SetObject(TObject *obj) { fObject = obj; }
  virtual void    SetInputList(TList *input) { fInput = input; }
  virtual TList  *GetOutputList() const { return fOutput; }
  virtual void    SlaveTerminate();
  virtual void    Terminate();

  //User defined functions are declared here
  void SetHstFileName(const char *HstFileName){ _HstFileName = HstFileName;}
  void SetSumFileName(const char *SumFileName){ _SumFileName = SumFileName;}
  void SetSample(int sample){_sample=sample;}
  void SetVerbose(int verbose){ _verbosity = verbose; }
  void SetData(int data){_data=data;}
  void SetYear(int year){_year = year;}
  void SetEra(TString era){_era=era;}
  void BookHistograms();
  void SortPt(int opt);
  float delta_phi(float phi1, float phi2);
  float transv_mass(float E_lep, float MET, float dphi);
  int GenMother(int ind, int mom_ind);

  public:
  struct Hists {
    //Histograms are declared here.
    TH1F *hist[10]; //This is an array of 10 histograms.
  };
  struct Lepton {//The struct 'Lepton' can store the following variables:
    TLorentzVector v;
    int id;
    int ind;
    //float wt;
    int status;
    //int flavor;
    int charge;
    //bool lepcleaning; bool taucleaning;
    int momid;
    //int genmatch;
    //int jetmatch;
  };
  
protected:
  Hists h;

private:
  //Global variables go here. Make them global only if necessary.
  TFile *_HstFile;
  const char *_HstFileName;
  const char *_SumFileName;
  int _verbosity,_exclude;
  int _data, _lep, _year, _sample;
  int nEvtTotal, nEvtRan; //Counters
  bool GoodEvt, GoodEvt2016, GoodEvt2017, GoodEvt2018; //Flags
  //float metpt, metphi;
  TString _era;
  //Event counters can be declared here.
  
  //######################
  // Declare arrays here:
  //######################
  vector<Lepton> RecoMu;
  
  ClassDef(nanoAna,0);
  
};

#endif

#ifdef nanoAna_cxx
void nanoAna::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the reader is initialized.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  //Decide whether to Run on Run2 or Run3
  _run3 = false;
  
  //Setting up the fReaders:
  fReader                .SetTree(tree);
  if(_run3)  fReader_Run3.SetTree(tree);
  else       fReader_Run2.SetTree(tree);
  
  if(_data == 0){              //If the input file is MC, activate fReader_MC 
    fReader_MC                .SetTree(tree);
    if(!_run3) fReader_Run2_MC.SetTree(tree);
    else       fReader_Run3_MC.SetTree(tree);
  }

  // Assigning address to the pointers for variables that have different names in Run2 and Run3.
  // These pointers need to be dereferenced twice to extract the value.
  if(_run3){
    ptr_fixedGridRhoFastjetAll =                  &Rho_fixedGridRhoFastjetAll;
    ptr_fixedGridRhoFastjetCentral =              &Rho_fixedGridRhoFastjetCentral;
    ptr_fixedGridRhoFastjetCentralCalo =          &Rho_fixedGridRhoFastjetCentralCalo;
    ptr_fixedGridRhoFastjetCentralChargedPileUp = &Rho_fixedGridRhoFastjetCentralChargedPileUp;
    ptr_fixedGridRhoFastjetCentralNeutral =       &Rho_fixedGridRhoFastjetCentralNeutral;
    ptr_Photon_pfRelIso03_all =                   &Photon_pfRelIso03_all_quadratic;
    ptr_Photon_pfRelIso03_chg =                   &Photon_pfRelIso03_chg_quadratic;
  }
  else{
    ptr_fixedGridRhoFastjetAll =                  &fixedGridRhoFastjetAll;
    ptr_fixedGridRhoFastjetCentral =            &fixedGridRhoFastjetCentral;
    ptr_fixedGridRhoFastjetCentralCalo =          &fixedGridRhoFastjetCentralCalo;
    ptr_fixedGridRhoFastjetCentralChargedPileUp = &fixedGridRhoFastjetCentralChargedPileUp;
    ptr_fixedGridRhoFastjetCentralNeutral =       &fixedGridRhoFastjetCentralNeutral;
    ptr_Photon_pfRelIso03_all =                   &Photon_pfRelIso03_all;
    ptr_Photon_pfRelIso03_chg =                   &Photon_pfRelIso03_chg;
  }
}

Bool_t nanoAna::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.
  
  return kTRUE;
}


#endif // #ifdef nanoAna_cxx
