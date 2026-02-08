
namespace calqi {
bool sinValid(const double &value) { return true; }

bool cosValid(const double &value) { return true; }

bool tanValid(const double &value) { return true; }

bool logValid(const double &value) { return value > 0; }

bool negValid(const double &value) { return true; }

bool sqrtValid(const double &value) { return value >= 0; }

bool asinValid(const double &value) { return value >= -1 && value <= 1; }

bool acosValid(const double &value) { return value >= -1 && value <= 1; }

bool atanValid(const double &value) { return true; }

bool sinhValid(const double &value) { return true; }

bool coshValid(const double &value) { return true; }

bool tanhValid(const double &value) { return true; }

bool atanhValid(const double &value) { return value > -1 && value < 1; }

bool asinhValid(const double &value) { return true; }

bool acoshValid(const double &value) { return value >= 1; }

} // namespace calqi