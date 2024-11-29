#include <stdexcept>
#include <algorithm>
#include <numeric>
#include "dataset.hpp"
#include "csv.hpp"

using namespace std;

void WaterDataset::loadData(const string& filename)
{
    csv::CSVReader reader(filename);

    data.clear();

    for (const auto& row: reader) {
        Water water{
            row["sample.samplingPoint.label"].get<std::string>(),
            row["sample.sampleDateTime"].get<std::string>(),
            row["determinand.label"].get<std::string>(),
            row["result"].get<double>(),
            row["determinand.unit.label"].get<std::string>(),
            row["sample.sampledMaterialType.label"].get<std::string>(),
            row["sample.isComplianceSample"].get<bool>(),
            row["sample.purpose.label"].get<std::string>(),
            row["sample.samplingPoint.easting"].get<int>(),
            row["sample.samplingPoint.northing"].get<int>()
        };
        data.push_back(row);
    }
}

void WaterDataset::checkDataExists() const
{
    if (size() == 0) {
        throw std::runtime_error("Dataset is empty!");
    }
}