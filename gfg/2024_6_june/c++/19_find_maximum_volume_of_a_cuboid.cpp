// TIME COMPLEXITY
// O(1)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        
        double length = (perimeter - sqrt(perimeter*perimeter - 24 * area))/ 12;
        double height = (perimeter / 4) - (2 * length);
        double volume = length * length * height;
        
        return volume;
    }
};