/*https://myntbit.com/training/vwap-calculator*/
#include <vector>
class VWAPCalculator {
private:
    double dollarvol, tradingvol;
public:
    VWAPCalculator() {
        dollarvol=0;
        tradingvol=0;
    }
    double addTrade(double price, double quantity){
        dollarvol+=price*quantity;
        tradingvol+=quantity;
        double res=dollarvol/tradingvol;
        return res;
    }
};
