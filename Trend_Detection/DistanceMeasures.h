#pragma once

#ifdef DISTANCEMEASURES_EXPORTS
#define DISTANCEMEASURES_API _declspec(dllexport)
#else
#define DISTANCEMEASURES_API _declspec(dllimport)
#endif // DISTANCEMEASURES_EXPORTS

#include <memory>
#include <string>
using namespace std;

class DISTANCEMEASURES_API DistanceMeasures {
public:
	DistanceMeasures();
	~DistanceMeasures();
	double euclidean(std::unique_ptr<double[]> &a, std::unique_ptr<double[]> &b, std::unique_ptr<int> &size);
	void SetName(std::string name);
	std::string GetName();
	std::string distance_measure_name;
};
