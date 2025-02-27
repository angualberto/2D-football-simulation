#ifndef EVOLUTION_H
#define EVOLUTION_H

#include <vector>

class Evolution {
public:
    Evolution();
    ~Evolution();

    void evolve();
};

std::vector<std::vector<double>> differential_evolution(const std::vector<std::vector<double>>& population, double F, int K);
std::vector<std::vector<double>> select_best_individuals(const std::vector<std::vector<double>>& population);
std::vector<std::vector<double>> optimize_formation(const std::vector<std::vector<double>>& formation, double F, int K);

#endif // EVOLUTION_H
