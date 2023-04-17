#include <iostream>
#include <map>

class Cantor {
 public:
  Cantor() = default;
  virtual ~Cantor() = default;

  virtual double Rate(const std::string& abbreviation) const = 0;
};

class FakeUsdCantor : public Cantor {
 public:
  FakeUsdCantor() {
    // rates_ map with values for ten most popular currencies relative to USD
    rates_ = {
      {"EUR", 0.85},
      {"JPY", 110.66},
      {"GBP", 0.73},
      {"CHF", 0.91},
      {"CAD", 1.25},
      {"AUD", 1.34},
      {"CNY", 6.47},
      {"HKD", 7.78},
      {"NZD", 1.44},
      {"KRW", 1153.89}
    };
  }

  double Rate(const std::string& abbreviation) const override {
    auto it = rates_.find(abbreviation);
    if (it != rates_.end()) {
      return it->second;
    }
    // Handle error case when currency abbreviation is not found
    return 0.0;
  }

 private:
  std::map<std::string, double> rates_;
};

class Currency {
 public:
  Currency() = default;
  virtual ~Currency() = default;

  virtual double ConvertedToDollars(const Cantor& cantor) const = 0;
  virtual std::string Abbreviation() const = 0;
  virtual double Amount() const = 0;
};

class Euro : public Currency{

private:
    std::string abbreviation;
    double amount;

public:
Euro(std::string x, double y)
{
    abbreviation = x;
    amount = y;
}
double ConvertedToDollars(const Cantor& cantor) const override
{
    double z=amount/cantor.Rate(this->abbreviation);
    return z;
}
std::string Abbreviation() const override
{
    return abbreviation;
}
double Amount() const override
{
    return amount;
}
};

class JPY : public Currency
{
private:
    std::string abbreviation;
    double amount;

public:
JPY(std::string x, double y)
{
    abbreviation = x;
    amount = y;
}
double ConvertedToDollars(const Cantor& cantor) const override
{
    double z=amount/cantor.Rate(this->abbreviation);
    return z;
}
std::string Abbreviation() const override
{
    return abbreviation;
}
double Amount() const override
{
    return amount;
}
};

int main() {
    FakeUsdCantor cantor;
    Euro o1("EUR", 100.0);
    double x =o1.ConvertedToDollars(cantor);
    std::cout << "Euro: " << o1.Amount() << std::endl << "w dolarach: " <<x << std::endl;
    JPY o3("JPY", 100.0);
    std::cout << "jpy: " << o1.Amount() << std::endl << "W dolarach: " << o3.ConvertedToDollars(cantor) << std::endl;
  return 0;
}
