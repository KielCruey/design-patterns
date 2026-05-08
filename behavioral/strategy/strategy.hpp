#include <memory> // unique_ptr
#include <string>
#include <vector>

// ========== Abstract Strategy ==========
class iAlgorithmStrategy {
public:
  ~iAlgorithmStrategy() = default;

  virtual std::vector<int> *doAlgorithm(std::vector<int> *data) = 0;
};

// ========== Concrete Strategy ==========
class IncreasingSort : public iAlgorithmStrategy {
public:
  std::vector<int> *doAlgorithm(std::vector<int> *data) override;
};

class DecreasingSort : public iAlgorithmStrategy {
public:
  std::vector<int> *doAlgorithm(std::vector<int> *data) override;
};

class Data {
public:
  explicit Data(std::vector<int> *data = nullptr);
  explicit Data(std::unique_ptr<iAlgorithmStrategy> &&strategy);
  ~Data();

  Data(Data &data);            // copy constructor
  Data &operator=(Data &data); // copy assignment

  void doAlgorithm(std::vector<int> *data);

  inline void setStrategy(std::unique_ptr<iAlgorithmStrategy> &&strategy);
  inline void setVector(std::vector<int> *data);

  std::vector<int> *sort();

private:
  std::unique_ptr<iAlgorithmStrategy> strategy;
  std::vector<int> *data;
};

#include "stragey.inl"