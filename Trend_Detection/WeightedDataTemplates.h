#pragma once
#ifdef WeightedDataTemplates_EXPORTS
#define WeightedDataTemplates_API _declspec(dllexport)
#else
#define WeightedDataTemplates_API _declspec(dllimport)
#endif // WeightedDataTemplates_EXPORTS

#include <memory>
#include <vector>
#include "DistanceMeasures.h"

class WeightedDataTemplates_API WeightedDataTemplates {
public:
	WeightedDataTemplates();
	~WeightedDataTemplates();
	int update(double kwargs);
	int get_results();
	double weight(std::unique_ptr<double[]> &reference_series, std::unique_ptr<double[]> &test_series, std::unique_ptr<int> &check_for_self);
	void set_up_distance_measures();

	int SMALL_NUMBER;
	int series_length;
	int reference_length;
	int Lambda;
	double trend_weight;
	double non_trend_weight;
	DistanceMeasures distance_measure;
private:
	int current_count;
	std::vector<double> total_series;

};
