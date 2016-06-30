#include "GTreeDetectorHits.h"



GTreeDetectorHits::GTreeDetectorHits(GTreeManager *Manager)    :
    GTree(Manager, TString("detectorHits")),
    nNaIHits(0),
    nPIDHits(0),
    nMWPCHits(0),
    nBaF2Hits(0),
    nVetoHits(0),
    nActiveHits(0)
{
}

GTreeDetectorHits::~GTreeDetectorHits()
{
}

void    GTreeDetectorHits::SetBranchAdresses()
{
    if(inputTree->GetBranch("nNaIHits")) inputTree->SetBranchAddress("nNaIHits", &nNaIHits);
    if(inputTree->GetBranch("NaIHits")) inputTree->SetBranchAddress("NaIHits", NaIHits);
    if(inputTree->GetBranch("NaICluster")) inputTree->SetBranchAddress("NaICluster", NaICluster);
    if(inputTree->GetBranch("NaIEnergy")) inputTree->SetBranchAddress("NaIEnergy", NaIEnergy);
    if(inputTree->GetBranch("NaITime")) inputTree->SetBranchAddress("NaITime", NaITime);
    if(inputTree->GetBranch("nPIDHits")) inputTree->SetBranchAddress("nPIDHits", &nPIDHits);
    if(inputTree->GetBranch("PIDHits")) inputTree->SetBranchAddress("PIDHits", PIDHits);
    if(inputTree->GetBranch("PIDEnergy")) inputTree->SetBranchAddress("PIDEnergy", PIDEnergy);
    if(inputTree->GetBranch("PIDTime")) inputTree->SetBranchAddress("PIDTime", PIDTime);
    if(inputTree->GetBranch("nMWPCHits")) inputTree->SetBranchAddress("nMWPCHits", &nMWPCHits);
    if(inputTree->GetBranch("MWPCHits")) inputTree->SetBranchAddress("MWPCHits", MWPCHits);
    if(inputTree->GetBranch("nBaF2Hits")) inputTree->SetBranchAddress("nBaF2Hits", &nBaF2Hits);
    if(inputTree->GetBranch("BaF2Hits")) inputTree->SetBranchAddress("BaF2Hits", BaF2Hits);
    if(inputTree->GetBranch("BaF2Cluster")) inputTree->SetBranchAddress("BaF2Cluster", BaF2Cluster);
    if(inputTree->GetBranch("BaF2Energy")) inputTree->SetBranchAddress("BaF2Energy", BaF2Energy);
    if(inputTree->GetBranch("BaF2Time")) inputTree->SetBranchAddress("BaF2Time", BaF2Time);
    if(inputTree->GetBranch("nVetoHits")) inputTree->SetBranchAddress("nVetoHits", &nVetoHits);
    if(inputTree->GetBranch("VetoHits")) inputTree->SetBranchAddress("VetoHits", VetoHits);
    if(inputTree->GetBranch("VetoEnergy")) inputTree->SetBranchAddress("VetoEnergy", VetoEnergy);
    if(inputTree->GetBranch("VetoTime")) inputTree->SetBranchAddress("VetoTime", VetoTime);
    if(inputTree->GetBranch("nActiveHits")) inputTree->SetBranchAddress("nActiveHits", &nActiveHits);
    if(inputTree->GetBranch("activeHits")) inputTree->SetBranchAddress("activeHits", activeHits);
    if(inputTree->GetBranch("activeEnergy")) inputTree->SetBranchAddress("activeEnergy", activeEnergy);
    if(inputTree->GetBranch("activeTime")) inputTree->SetBranchAddress("activeTime", activeTime);
    if(inputTree->GetBranch("activePosX")) inputTree->SetBranchAddress("activePosX", activePosX);
    if(inputTree->GetBranch("activePosY")) inputTree->SetBranchAddress("activePosY", activePosY);
    if(inputTree->GetBranch("activePosZ")) inputTree->SetBranchAddress("activePosZ", activePosZ);
}

void    GTreeDetectorHits::SetBranches()
{
    outputTree = inputTree->CloneTree(0);
}

void    GTreeDetectorHits::SetNewBranchAddress(const char* bname, void* var)
{
    inputTree->SetBranchAddress(bname,var);
}
