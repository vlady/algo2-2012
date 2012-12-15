#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> Job;
typedef vector<Job> JobList; 

int num_jobs;
JobList jobs; // (weight, length)

bool ratio(Job a, Job b) {
  // larger ratio wins: weight/length
  return a.first * b.second > b.first * a.second;
} 

bool diff(Job a, Job b) {
  // larger difference wins
  LL d1 = a.first - a.second;
  LL d2 = b.first - b.second;
  if (d1 != d2) return d1 > d2;
  return a.first > b.first;
}

LL evaluate_jobs(const JobList& jobs) {
  int num_jobs = jobs.size();
  LL sum_lengths = 0;
  LL weighted_sum = 0;
  for (int idx = 0; idx < num_jobs; ++idx) {
    sum_lengths += jobs[idx].second;
    weighted_sum += jobs[idx].first * sum_lengths;
  }
  return weighted_sum;
}

void read_input() {
  freopen("jobs.txt", "r", stdin);
  cin >> num_jobs;
  jobs.clear();

  for (int idx = 0; idx < num_jobs; ++idx) {
    int weight, length;
    cin >> weight >> length;
    jobs.push_back(make_pair(weight, length));
  }
  fclose(stdin);
}

int main() {
  read_input();

  cout << "Initial: " << evaluate_jobs(jobs) << '\n';
  sort(jobs.begin(), jobs.end(), diff);
  cout << "Non-optimal: " << evaluate_jobs(jobs) << '\n';
  sort(jobs.begin(), jobs.end(), ratio);
  cout << "Optimal: " << evaluate_jobs(jobs) << '\n';
  return 0;  
}
