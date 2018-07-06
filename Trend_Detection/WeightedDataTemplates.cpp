#include "stdafx.h"
#include "WeightedDataTemplates.h"
#include "DistanceMeasures.h"
#include <numeric>

WeightedDataTemplates::WeightedDataTemplates()
{
	trend_weight = NULL;
	non_trend_weight = NULL;
	SMALL_NUMBER = 0.001;
	series_length = 50;
	reference_length = 210;
	Lambda = 1;
	set_up_distance_measures();
}
WeightedDataTemplates::~WeightedDataTemplates()
{
}

//TODO finish function
int WeightedDataTemplates::update(double kwargs)
{
	current_count = kwargs;
	total_series.push_back(current_count);
	bool check_for_self = false;
	int total_series_sum = std::accumulate(total_series.begin(), total_series.end(), 0);
	if (total_series.size() < reference_length || total_series_sum == 0) {
		trend_weight = 0.0;
		non_trend_weight = 0.0;
		return 0;
	}
	//TODO transformed_series = ....
}
int WeightedDataTemplates::get_results()
{
	if (trend_weight == NULL || non_trend_weight == NULL) {
		return -1;
	}
	if (non_trend_weight == 0) {
		non_trend_weight = SMALL_NUMBER;
	}
	return trend_weight / non_trend_weight;
}
double WeightedDataTemplates::weight(std::unique_ptr<double[]> &reference_series, std::unique_ptr<double []> &test_series, std::unique_ptr<int> &check_for_self)
{
	if (check_for_self) {
		if (reference_series == test_series) {
			return 0;
		}
	}
	double min_distance = 1.79769e+308;
	//TODO initialize d
	std::unique_ptr<int>size(new int(10));
	double d = distance_measure.euclidean(reference_series,test_series, size);
	if (d < min_distance){
		min_distance = d;
	}
	return pow(-(double)min_distance,Lambda);
}
void WeightedDataTemplates::set_up_distance_measures()
{
	distance_measure.SetName("euclidean");
}
