// SPDX-License-Identifier: BSD-2-Clause

// This code is part of the sfizz library and is licensed under a BSD 2-clause
// license. You should have receive a LICENSE.md file along with the code.
// If not, contact the sfizz maintainers at https://github.com/sfztools/sfizz

struct Meta {};
struct UI {};

/**
   Base of the faust DSP for filters
 */
struct sfzFilterDsp {
public:
    virtual ~sfzFilterDsp() {}

    virtual void init(int) = 0;
    virtual void instanceClear() = 0;
    virtual void compute(int, float **, float **) = 0;

    virtual void configureStandard(float, float, float) {}
    virtual void configureEq(float, float, float) {}
};

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#include "gen/filters/sfzApf1p.cxx"
#include "gen/filters/sfzBpf1p.cxx"
#include "gen/filters/sfzBpf2p.cxx"
#include "gen/filters/sfzBpf4p.cxx"
#include "gen/filters/sfzBpf6p.cxx"
#include "gen/filters/sfzBrf1p.cxx"
#include "gen/filters/sfzBrf2p.cxx"
#include "gen/filters/sfzHpf1p.cxx"
#include "gen/filters/sfzHpf2p.cxx"
#include "gen/filters/sfzHpf4p.cxx"
#include "gen/filters/sfzHpf6p.cxx"
#include "gen/filters/sfzLpf1p.cxx"
#include "gen/filters/sfzLpf2p.cxx"
#include "gen/filters/sfzLpf4p.cxx"
#include "gen/filters/sfzLpf6p.cxx"
#include "gen/filters/sfzPink.cxx"
#include "gen/filters/sfzLpf2pSv.cxx"
#include "gen/filters/sfzHpf2pSv.cxx"
#include "gen/filters/sfzBpf2pSv.cxx"
#include "gen/filters/sfzBrf2pSv.cxx"
#include "gen/filters/sfzLsh.cxx"
#include "gen/filters/sfzHsh.cxx"
#include "gen/filters/sfzPeq.cxx"
#include "gen/filters/sfzEq.cxx"

#include "gen/filters/sfz2chApf1p.cxx"
#include "gen/filters/sfz2chBpf1p.cxx"
#include "gen/filters/sfz2chBpf2p.cxx"
#include "gen/filters/sfz2chBpf4p.cxx"
#include "gen/filters/sfz2chBpf6p.cxx"
#include "gen/filters/sfz2chBrf1p.cxx"
#include "gen/filters/sfz2chBrf2p.cxx"
#include "gen/filters/sfz2chHpf1p.cxx"
#include "gen/filters/sfz2chHpf2p.cxx"
#include "gen/filters/sfz2chHpf4p.cxx"
#include "gen/filters/sfz2chHpf6p.cxx"
#include "gen/filters/sfz2chLpf1p.cxx"
#include "gen/filters/sfz2chLpf2p.cxx"
#include "gen/filters/sfz2chLpf4p.cxx"
#include "gen/filters/sfz2chLpf6p.cxx"
#include "gen/filters/sfz2chPink.cxx"
#include "gen/filters/sfz2chLpf2pSv.cxx"
#include "gen/filters/sfz2chHpf2pSv.cxx"
#include "gen/filters/sfz2chBpf2pSv.cxx"
#include "gen/filters/sfz2chBrf2pSv.cxx"
#include "gen/filters/sfz2chLsh.cxx"
#include "gen/filters/sfz2chHsh.cxx"
#include "gen/filters/sfz2chPeq.cxx"
#include "gen/filters/sfz2chEq.cxx"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

/**
   Wrapper of the most common kind of resonant filter
   Parameterized by cutoff and Q
 */
template <class F> struct sfzFilter : public F {
    void configureStandard(float cutoff, float q, float pksh) override
    {
        F::fCutoff = cutoff;
        F::fQ = q;
        (void)pksh;
    }
};

/**
   Wrapper of non resonant filters
   Parameterized by cutoff only
 */
template <class F> struct sfzFilterNoQ : public F {
    void configureStandard(float cutoff, float q, float pksh) override
    {
        F::fCutoff = cutoff;
        (void)q;
        (void)pksh;
    }
};

/**
   Wrapper of fixed filters
   Not parameterized
 */
template <class F> struct sfzFilterNoCutoff : public F {
    void configureStandard(float cutoff, float q, float pksh) override
    {
        (void)cutoff;
        (void)q;
        (void)pksh;
    }
};

/**
   Wrapper of resonant filters with a gain control for peak or shelf
   Parameterized by cutoff, Q, peak/shelf gain
 */
template <class F> struct sfzFilterPkSh : public F {
    void configureStandard(float cutoff, float q, float pksh) override
    {
        F::fCutoff = cutoff;
        F::fQ = q;
        F::fPkShGain = pksh;
    }
};

/**
   Wrapper of equalizer filters with a bandwidth control
   Parameterized by cutoff, bandwidth, peak/shelf gain
 */
template <class F> struct sfzFilterEq : public F {
    void configureEq(float cutoff, float bw, float pksh) override
    {
        F::fCutoff = cutoff;
        F::fBandwidth = bw;
        F::fPkShGain = pksh;
    }
};

struct sfzLpf1p final : public sfzFilterNoQ<faustLpf1p> {};
struct sfzLpf2p final : public sfzFilter<faustLpf2p> {};
struct sfzLpf4p final : public sfzFilter<faustLpf4p> {};
struct sfzLpf6p final : public sfzFilter<faustLpf6p> {};
struct sfzHpf1p final : public sfzFilterNoQ<faustHpf1p> {};
struct sfzHpf2p final : public sfzFilter<faustHpf2p> {};
struct sfzHpf4p final : public sfzFilter<faustHpf4p> {};
struct sfzHpf6p final : public sfzFilter<faustHpf6p> {};
struct sfzBpf1p final : public sfzFilterNoQ<faustBpf1p> {};
struct sfzBpf2p final : public sfzFilter<faustBpf2p> {};
struct sfzBpf4p final : public sfzFilter<faustBpf4p> {};
struct sfzBpf6p final : public sfzFilter<faustBpf6p> {};
struct sfzApf1p final : public sfzFilterNoQ<faustApf1p> {};
struct sfzBrf1p final : public sfzFilterNoQ<faustBrf1p> {};
struct sfzBrf2p final : public sfzFilter<faustBrf2p> {};
struct sfzPink final : public sfzFilterNoCutoff<faustPink> {};
struct sfzLpf2pSv final : public sfzFilter<faustLpf2pSv> {};
struct sfzHpf2pSv final : public sfzFilter<faustHpf2pSv> {};
struct sfzBpf2pSv final : public sfzFilter<faustBpf2pSv> {};
struct sfzBrf2pSv final : public sfzFilter<faustBrf2pSv> {};
struct sfzLsh final : public sfzFilterPkSh<faustLsh> {};
struct sfzHsh final : public sfzFilterPkSh<faustHsh> {};
struct sfzPeq final : public sfzFilterPkSh<faustPeq> {};
struct sfzEq final : public sfzFilterEq<faustEq> {};

struct sfz2chLpf1p final : public sfzFilterNoQ<faust2chLpf1p> {};
struct sfz2chLpf2p final : public sfzFilter<faust2chLpf2p> {};
struct sfz2chLpf4p final : public sfzFilter<faust2chLpf4p> {};
struct sfz2chLpf6p final : public sfzFilter<faust2chLpf6p> {};
struct sfz2chHpf1p final : public sfzFilterNoQ<faust2chHpf1p> {};
struct sfz2chHpf2p final : public sfzFilter<faust2chHpf2p> {};
struct sfz2chHpf4p final : public sfzFilter<faust2chHpf4p> {};
struct sfz2chHpf6p final : public sfzFilter<faust2chHpf6p> {};
struct sfz2chBpf1p final : public sfzFilterNoQ<faust2chBpf1p> {};
struct sfz2chBpf2p final : public sfzFilter<faust2chBpf2p> {};
struct sfz2chBpf4p final : public sfzFilter<faust2chBpf4p> {};
struct sfz2chBpf6p final : public sfzFilter<faust2chBpf6p> {};
struct sfz2chApf1p final : public sfzFilterNoQ<faust2chApf1p> {};
struct sfz2chBrf1p final : public sfzFilterNoQ<faust2chBrf1p> {};
struct sfz2chBrf2p final : public sfzFilter<faust2chBrf2p> {};
struct sfz2chPink final : public sfzFilterNoCutoff<faust2chPink> {};
struct sfz2chLpf2pSv final : public sfzFilter<faust2chLpf2pSv> {};
struct sfz2chHpf2pSv final : public sfzFilter<faust2chHpf2pSv> {};
struct sfz2chBpf2pSv final : public sfzFilter<faust2chBpf2pSv> {};
struct sfz2chBrf2pSv final : public sfzFilter<faust2chBrf2pSv> {};
struct sfz2chLsh final : public sfzFilterPkSh<faust2chLsh> {};
struct sfz2chHsh final : public sfzFilterPkSh<faust2chHsh> {};
struct sfz2chPeq final : public sfzFilterPkSh<faust2chPeq> {};
struct sfz2chEq final : public sfzFilterEq<faust2chEq> {};
