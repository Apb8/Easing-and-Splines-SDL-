#include <cmath>
#include <map>

#include "functions.h"

#ifndef PI
#define PI 3.1415926545
#endif

//SDL version still testing, the code below is extracted from @nicolausYes project

double easeInSine(double t) {
    return sin(1.5707963 * t);
}

double easeOutSine(double t) {
    return 1 + sin(1.5707963 * (--t));
}

double easeInOutSine(double t) {
    return 0.5 * (1 + sin(3.1415926 * (t - 0.5)));
}

double easeInQuad(double t) {
    return t * t;
}

double easeOutQuad(double t) {
    return t * (2 - t);
}

double easeInOutQuad(double t) {
    return t < 0.5 ? 2 * t * t : t * (4 - 2 * t) - 1;
}

double easeInCubic(double t) {
    return t * t * t;
}

double easeOutCubic(double t) {
    return 1 + (--t) * t * t;
}

double easeInOutCubic(double t) {
    return t < 0.5 ? 4 * t * t * t : 1 + (--t) * (2 * (--t)) * (2 * t);
}

double easeInExpo(double t) {
    return (pow(2, 8 * t) - 1) / 255;
}

double easeOutExpo(double t) {
    return 1 - pow(2, -8 * t);
}

double easeInOutExpo(double t) {
    if (t < 0.5) {
        return (pow(2, 16 * t) - 1) / 510;
    }
    else {
        return 1 - 0.5 * pow(2, -16 * (t - 0.5));
    }
}

double easeInBounce(double t) {
    return pow(2, 6 * (t - 1)) * abs(sin(t * PI * 3.5));
}

double easeOutBounce(double t) {
    return 1 - pow(2, -6 * t) * abs(cos(t * PI * 3.5));
}

double easeInOutBounce(double t) {
    if (t < 0.5) {
        return 8 * pow(2, 8 * (t - 1)) * abs(sin(t * PI * 7));
    }
    else {
        return 1 - 8 * pow(2, -8 * t) * abs(sin(t * PI * 7));
    }
}

easingFunction getEasingFunction(easing_functions function)
{
    static std::map< easing_functions, easingFunction > easingFunctions;
    if (easingFunctions.empty())
    {
        easingFunctions.insert(std::make_pair(EaseInSine, easeInSine));
        easingFunctions.insert(std::make_pair(EaseOutSine, easeOutSine));
        easingFunctions.insert(std::make_pair(EaseInOutSine, easeInOutSine));
        easingFunctions.insert(std::make_pair(EaseInQuad, easeInQuad));
        easingFunctions.insert(std::make_pair(EaseOutQuad, easeOutQuad));
        easingFunctions.insert(std::make_pair(EaseInOutQuad, easeInOutQuad));
        easingFunctions.insert(std::make_pair(EaseInCubic, easeInCubic));
        easingFunctions.insert(std::make_pair(EaseOutCubic, easeOutCubic));
        easingFunctions.insert(std::make_pair(EaseInOutCubic, easeInOutCubic));
        easingFunctions.insert(std::make_pair(EaseInExpo, easeInExpo));
        easingFunctions.insert(std::make_pair(EaseOutExpo, easeOutExpo));
        easingFunctions.insert(std::make_pair(EaseInOutExpo, easeInOutExpo));
        easingFunctions.insert(std::make_pair(EaseInBounce, easeInBounce));
        easingFunctions.insert(std::make_pair(EaseOutBounce, easeOutBounce));
        easingFunctions.insert(std::make_pair(EaseInOutBounce, easeInOutBounce));

    }

    auto it = easingFunctions.find(function);
    return it == easingFunctions.end() ? nullptr : it->second;
}