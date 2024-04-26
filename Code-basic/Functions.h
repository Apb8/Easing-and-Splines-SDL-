#pragma once 

enum easing_functions
{
	EaseInSine,
	EaseOutSine,
	EaseInOutSine,
	EaseInQuad,
	EaseOutQuad,
	EaseInOutQuad,
	EaseInCubic,
	EaseOutCubic,
	EaseInOutCubic,
	EaseInExpo,
	EaseOutExpo,
	EaseInOutExpo,
	EaseInBounce,
	EaseOutBounce,
	EaseInOutBounce
};

typedef double(*easingFunction)(double);

easingFunction getEasingFunction(easing_functions function); 