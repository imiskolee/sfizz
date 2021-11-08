#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
/* ------------------------------------------------------------
author: "Jean Pierre Cimalando"
license: "BSD-2-Clause"
name: "sfz_filters"
Code generated with Faust 2.30.5 (https://faust.grame.fr)
Compilation options: -lang cpp -inpl -es 1 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __faust2chLpf1p_H__
#define  __faust2chLpf1p_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <math.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS faust2chLpf1p
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif


//[Before:class]
class faust2chLpf1p : public sfzFilterDsp {
	//[Begin:class]

	
 private:
	
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	FAUSTFLOAT fHslider0;
	double fRec1[2];
	double fRec0[2];
	double fRec2[2];
	
 public:
	

	static constexpr int getNumInputs() {
		return 2;
	}
	static constexpr int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
		//[Begin:classInit]
		//[End:classInit]
	}
	
	void instanceConstants(int sample_rate) {
		//[Begin:instanceConstants]
		fSampleRate = sample_rate;
		fConst0 = double(fSampleRate);
		fConst1 = std::exp((0.0 - (1000.0 / fConst0)));
		fConst2 = (1.0 / fConst0);
		//[End:instanceConstants]
	}
	
	void instanceResetUserInterface() {
		//[Begin:instanceResetUserInterface]
		fHslider0 = FAUSTFLOAT(440.0);
		//[End:instanceResetUserInterface]
	}
	
	void instanceClear() {
		//[Begin:instanceClear]
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec1[l0] = 0.0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec0[l1] = 0.0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0;
		}
		//[End:instanceClear]
	}
	
	void init(int sample_rate) {
		//[Begin:init]
		classInit(sample_rate);
		instanceInit(sample_rate);
		//[End:init]
	}
	void instanceInit(int sample_rate) {
		//[Begin:instanceInit]
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
		//[End:instanceInit]
	}
	
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	
	void compute(int count, FAUSTFLOAT const* const* inputs, FAUSTFLOAT* const* outputs) {
		//[Begin:compute]
		FAUSTFLOAT const* input0 = inputs[0];
		FAUSTFLOAT const* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		double fSlow0 = (fSmoothEnable ? fConst1 : 0.0);
		double fSlow1 = (std::exp((fConst2 * (0.0 - (6.2831853071795862 * std::min<double>(20000.0, std::max<double>(1.0, double(fHslider0))))))) * (1.0 - fSlow0));
		for (int i = 0; (i < count); i = (i + 1)) {
			double fTemp0 = double(input0[i]);
			double fTemp1 = double(input1[i]);
			fRec1[0] = ((fSlow0 * fRec1[1]) + fSlow1);
			fRec0[0] = (fTemp0 + (fRec1[0] * fRec0[1]));
			double fTemp2 = (1.0 - fRec1[0]);
			output0[i] = FAUSTFLOAT((fRec0[0] * fTemp2));
			fRec2[0] = (fTemp1 + (fRec1[0] * fRec2[1]));
			output1[i] = FAUSTFLOAT((fRec2[0] * fTemp2));
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
		}
		//[End:compute]
	}


    FAUSTFLOAT getCutoff() const { return fHslider0; }
    void setCutoff(FAUSTFLOAT value) { fHslider0 = value; }

	//[End:class]
};
//[After:class]


#endif
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#undef FAUSTFLOAT
#undef FAUSTCLASS