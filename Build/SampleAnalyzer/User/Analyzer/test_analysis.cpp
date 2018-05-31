#include "SampleAnalyzer/User/Analyzer/test_analysis.h"
using namespace MA5;
using namespace std;


std::vector<RecLeptonFormat> test_analysis::GetBaselineElectrons(const std::vector<RecLeptonFormat> &candidate_electrons) {
  std::vector<RecLeptonFormat> result;
  for (auto candidate : candidate_electrons) {
//    cout << "Momentum: " << candidate.pt() << endl;
//    cout << "Pseudorapidity: " << candidate.abseta() << endl;
    if(candidate.pt() < 5.7)
      continue;
    if(candidate.abseta() > 2.47)
      continue;
    result.push_back(candidate);
  }
  cout << "Number of baseline electrons found: " << result.size() << endl;
  return result;
}

std::vector<RecLeptonFormat> test_analysis::GetBaselineMuons(const std::vector<RecLeptonFormat> &candidate_muons) {
  std::vector<RecLeptonFormat> result;
  for (auto candidate : candidate_muons) {
//    cout << "Momentum: " << candidate.pt() << endl;
//    cout << "Pseudorapidity: " << candidate.abseta() << endl;
    if(candidate.pt() < 4.0)
      continue;
    if(candidate.abseta() > 2.7)
      continue;
    result.push_back(candidate);
  }
  cout << "Number of baseline muons found: " << result.size() << endl;
  return result;
}

std::vector<RecJetFormat> test_analysis::GetBaselineJets(const std::vector<RecJetFormat> &candidate_jets) {
  std::vector<RecJetFormat> result;
  for (auto candidate : candidate_jets) {
//    cout << "Momentum: " << candidate.pt() << endl;
//    cout << "Pseudorapidity: " << candidate.abseta() << endl;
    if(candidate.pt() < 20.0)
      continue;
    result.push_back(candidate);
  }
  cout << "Number of baseline jets found: " << result.size() << endl;
  return result;
}
// -----------------------------------------------------------------------------
// Initialize
// function called one time at the beginning of the analysis
// -----------------------------------------------------------------------------
bool test_analysis::Initialize(const MA5::Configuration& cfg, const std::map<std::string,std::string>& parameters)
{
  cout << "BEGIN Initialization" << endl;
  // initialize variables, histos
  cout << "END   Initialization" << endl;
  return true;
}

// -----------------------------------------------------------------------------
// Finalize
// function called one time at the end of the analysis
// -----------------------------------------------------------------------------
void test_analysis::Finalize(const SampleFormat& summary, const std::vector<SampleFormat>& files)
{
  cout << "BEGIN Finalization" << endl;
  // saving histos
  cout << "END   Finalization" << endl;
}

// -----------------------------------------------------------------------------
// Execute
// function called each time one event is read
// -----------------------------------------------------------------------------
bool test_analysis::Execute(SampleFormat& sample, const EventFormat& event)
{
  auto baseline_electrons = GetBaselineElectrons(event.rec()->electrons());
  auto baseline_muons = GetBaselineMuons(event.rec()->muons());
  auto baseline_jets = GetBaselineJets(event.rec()->jets());

  cout << "Electrons count: " << event.rec()->electrons().size() << endl;
  cout << "Photons count: " << event.rec()->photons().size() << endl;
  cout << "Muons count: " << event.rec()->muons().size() << endl;
  
  return true;
}

