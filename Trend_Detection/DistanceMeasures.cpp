#include "stdafx.h"
#include "DistanceMeasures.h"

#include <cmath>


DistanceMeasures::DistanceMeasures() {
}
DistanceMeasures::~DistanceMeasures() {
}
double DistanceMeasures::euclidean(std::unique_ptr<double[]> &a, std::unique_ptr<double[]> &b, std::unique_ptr<int> &size)
{
	double sum = 0;
	for (int i = 0; i < *size; i++) {
		sum += std::abs(a[i] - b[i]);
	}
	return sum;
}

void DistanceMeasures::SetName(std::string name) 
{
	distance_measure_name = name;
}
std::string DistanceMeasures::GetName() 
{
	return distance_measure_name;
}