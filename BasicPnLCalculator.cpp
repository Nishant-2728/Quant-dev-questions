/*https://myntbit.com/training/pnl-basic-calculator*/
#include <vector>
class PnLCalculator {
public:
    PnLCalculator() {
    }
    double calculateRealizedPnL(double entryPrice, double exitPrice, double quantity, double side) {
        double res=(exitPrice-entryPrice)*side*quantity;
        return res;
    }
};
