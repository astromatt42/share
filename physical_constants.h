#ifndef physical_constants_h
#define physical_constants_h

/*
 * Define some physical constants and unit conversions for later use
 */

//Electron mass
const double m_e__GeV = 0.51099895000e-3;
const double m_e__g = 9.10938188e-28;

//Hydrogen mass
const double m_H__g = 1.66053904020e-24;
const double m_H__kg = 1.66053904020e-27;

//Deuteron mass
const double m_d__GeV = 1.875;

//Muon mass
const double m_mu__GeV = 0.1056583755;

//proton mass
const double m_p__GeV = 0.93827208816;

//pion masses
const double m_pi0__GeV = 0.1349766;
const double m_piC__GeV = 0.13957018;

//Classical electron radius cgs
const double r_0__cm = 2.8179e-13;
//electron charge statC/esu
const double e__esu = 4.80320451e-10;
//Speed of light
const double c__cmsm1 = 2.99792458e10;
//Boltzmann constant
const double k_B__GeVKm1 = 8.617333262145e-14;
const double k_B__ergKm1 = 1.380649e-16;
//Planck's constant
const double h__GeVs = 4.135667696e-24;
const double h__ergs = 6.626196e-27;
const double h__Js = 6.62607015e-34;
//Thomson cross section
const double sigma_T__mb = 665.2487158;
//Radiation constant
const double arad__GeVcmm3Km4 = 4.722e-12;
//Fine-structure constant
const double alpha = 7.2973525693e-3;

//millibarn in cm^2
const double mb__cm2 = 1e-27;
//pc in cm
const double pc__cm = 3.0857e18;
//erg in GeV
const double erg__GeV = 624.15;
const double GeV__erg = 1./624.15;
//year in s
const double yr__s = 3.15576e7;

//solar luminosity
const double Lsol__GeVsm1 = 2.3882e36;
const double Lsol__dyncmsm1 = 3.828e33;

//solar mass
const double Msol__g = 1.98847e33;
const double Msol__kg = 1.98847e30;

//Euler's constant
const double gamma_Euler = 0.5772156649;

//CMB temp at z = 0
const double T_0_CMB__K = 2.7255;

//Gravitational constant
const double G__pcMsolm1km2sm2 = 4.30091e-3;

#endif
