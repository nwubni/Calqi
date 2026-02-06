
namespace calqi {
bool sinValid(const double &value) { return value >= -1 && value <= 1; }

bool cosValid(const double &value) { return value >= -1 && value <= 1; }

bool tanValid(const double &value) { return true; }

bool logValid(const double &value) { return value > 0; }

bool sqrtValid(const double &value) { return value >= 0; }

bool asinValid(const double &value) { return value >= -1 && value <= 1; }

bool acosValid(const double &value) { return value >= -1 && value <= 1; }

bool atanValid(const double &value) { return true; }
} // namespace calqi