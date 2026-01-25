#include <bits/stdc++.h>
using namespace std;

struct Colors {
    string haxCode;

    // Colors(string code) : haxCode(code) {}

    Colors(string code){
        
        // Add directly if color is in hex format
        if(code[0] == '#'){
            haxCode = code;
            return;
        }

        if(code.substr(0, 3) == "RGB"){
            int r, g, b;
            sscanf(code.c_str(), "RGB(%d, %d, %d)", &r, &g, &b);
            char buffer[8];
            sprintf(buffer, "#%02X%02X%02X", r, g, b);
            haxCode = string(buffer);
        }else if(code.substr(0, 4) == "CMYK"){
            double c, m, y, k;
            sscanf(code.c_str(), "CMYK(%lf%%, %lf%%, %lf%%, %lf%%)", &c, &m, &y, &k);
            c /= 100.0; m /= 100.0; y /= 100.0; k /= 100.0;

            int r = static_cast<int>(255 * (1 - c) * (1 - k));
            int g = static_cast<int>(255 * (1 - m) * (1 - k));
            int b = static_cast<int>(255 * (1 - y) * (1 - k));

            char buffer[8];
            sprintf(buffer, "#%02X%02X%02X", r, g, b);
            haxCode = string(buffer);
        }
    }

    void toRGB() {
        int r = stoi(haxCode.substr(1, 2), nullptr, 16);
        int g = stoi(haxCode.substr(3, 2), nullptr, 16);
        int b = stoi(haxCode.substr(5, 2), nullptr, 16);
        cout << "RGB(" << r << ", " << g << ", " << b << ")\n";
    }

    void toCMYK() {
        int r = stoi(haxCode.substr(1, 2), nullptr, 16);
        int g = stoi(haxCode.substr(3, 2), nullptr, 16);
        int b = stoi(haxCode.substr(5, 2), nullptr, 16);

        double rPrime = r / 255.0;
        double gPrime = g / 255.0;
        double bPrime = b / 255.0;

        double k = 1 - max({rPrime, gPrime, bPrime});
        double c = (1 - rPrime - k) / (1 - k);
        double m = (1 - gPrime - k) / (1 - k);
        double y = (1 - bPrime - k) / (1 - k);

        cout << "CMYK(" << c * 100 << "%, " << m * 100 << "%, " << y * 100 << "%, " << k * 100 << "%)\n";
    }

    void toHSL() {
        int r = stoi(haxCode.substr(1, 2), nullptr, 16);
        int g = stoi(haxCode.substr(3, 2), nullptr, 16);
        int b = stoi(haxCode.substr(5, 2), nullptr, 16);

        double rPrime = r / 255.0;
        double gPrime = g / 255.0;
        double bPrime = b / 255.0;

        double maxVal = max({rPrime, gPrime, bPrime});
        double minVal = min({rPrime, gPrime, bPrime});
        double h, s, l;
        l = (maxVal + minVal) / 2.0;

        if (maxVal == minVal) {
            h = s = 0; // achromatic
        } else {
            double d = maxVal - minVal;
            s = l > 0.5 ? d / (2.0 - maxVal - minVal) : d / (maxVal + minVal);

            if (maxVal == rPrime) {
                h = (gPrime - bPrime) / d + (gPrime < bPrime ? 6 : 0);
            } else if (maxVal == gPrime) {
                h = (bPrime - rPrime) / d + 2;
            } else {
                h = (rPrime - gPrime) / d + 4;
            }
            h /= 6;
        }

        cout << "HSL(" << h * 360 << "°, " << s * 100 << "%, " << l * 100 << "%)\n";
    }
};

int main() {
    Colors color("RGB(255, 0, 0)");

    color.toRGB();
    color.toCMYK();
    color.toHSL();

    return 0;
}