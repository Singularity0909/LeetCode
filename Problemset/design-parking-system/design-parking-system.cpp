
// @Title: 设计停车系统 (Design Parking System)
// @Author: Singularity0909
// @Date: 2020-10-04 22:35:41
// @Runtime: 144 ms
// @Memory: 32.5 MB

class ParkingSystem {
public:
    int a[4];

    ParkingSystem(int big, int medium, int small)
    {
        a[1] = big;
        a[2] = medium;
        a[3] = small;
    }

    bool addCar(int carType)
    {
        if (not a[carType]) {
            return false;
        }
        --a[carType];
        return true;
    }
};
