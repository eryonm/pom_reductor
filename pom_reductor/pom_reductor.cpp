// PartsOfMachines.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;



double Round3(double value)
{
	return(round(value * 1000) / 1000);
}


void cepPer(int& q2, double& T2, double& T3, double& n2, double& w2, double& uTSP, double z3, double z4, double Ke,
	double p, double pp, double t, double Q, double q, double Aon, double dd1, double vc, double Ftc,
	double Lt, double at, double del, double Zsum, double ac,
	double Fv, double KF, double Ff, double FB, double dd3, double De3, double s)
{
	z3 = round(31 - (2 * uTSP));
	z4 = round(z3 * uTSP);
	cout << "z3 = " << z3 << "\tz4 = " << z4 << endl;

	double uT; uT = z4 / z3;
	cout << "Отклонение " << (uTSP - uT) * 100 / uTSP << endl;

	cout << "Введите допускаемое давление в шарнирах цепи [p]" << endl;
	cin >> pp;

	Ke = 1.25;
	Q = 0; q = 0; Aon = 0; dd1 = 0;
	t = round(2.8 * pow(T3 * 1000 * Ke / (z3 * pp), 0.333));
	cout << "t = " << t << endl;

	cout << "Введите t,Q,q,Aon,d1" << endl;
	cin >> t >> Q >> q >> Aon >> dd1;

	vc = z3 * t * n2 / (60 * 1000);
	cout << "Скорость цепи V = " << vc << endl;

	Ftc = T2 * w2 / vc;
	cout << "Окружная сила Ftc = " << Ftc << endl;

	p = Ftc * Ke / Aon;
	cout << "Проверяем давление в шарнире p = " << p << endl;

	cout << "Введите [p] при t = " << t << endl;
	cin >> pp;

	double ptemp = pp * (1 + (0.01 * (z3 - 17)));

	cout << "Уточняем [p] = " << ptemp << endl;

	if (p <= ptemp)
	{
		cout << "p <= [p]\t" << p << "<=" << ptemp << endl;
		cout << "Условие выполнено" << endl;
	}
	else {
		cout << "Условие не выполнено" << endl;
	}

	del = (z4 - z3) / (2 * 3.14);
	Zsum = z3 + z4;


	Lt = floor(((2 * 50) + (0.5 * Zsum) + (pow(del, 2) / 50)));

	cout << "Число звеньев цепи Lt = " << Lt << endl;

	if (q2 == 1)
	{
		ac = 0.25 * t * (Lt - (0.5 * Zsum) + pow(pow(Lt - (0.5 * Zsum), 2) - (8 * del * del), 0.5));
		cout << "Уточняем межосевое расстояние" << ac * 0.004 << endl;
		ac *= 0.004;
	}
	else if (q2 == 2)
	{
		ac = 50 * t / 1000;
	}

	Fv = q * vc * vc;
	KF = 1.5;
	Ff = 9.81 * KF * q * ac;
	FB = Ftc + (2 * Ff);

	cout << "Межосевое расстояние ac = " << ac << endl;
	cout << "Силы,действующие на цепь\n";
	cout << "От центробежных сил Fv" << Fv << endl;
	cout << "От провисания цепи" << Ff << endl;
	cout << "Нагрузка на валы FB = " << FB << endl;

	double tmp = 180 / z3;
	tmp *= 3.14 / 180;

	dd3 = t / sin(tmp);
	De3 = t * (cos(tmp) / sin(tmp) + 0.7) - (0.3 * dd1);

	cout << "Диаметры ведущей звездочки\n";
	cout << "Делительной окружности d3 = " << dd3 << endl;
	cout << "Наружной De3 = " << De3 << endl;

	cout << "Проверяем коэффициент запаса цепи на растяжение" << endl;

	s = Q * 1000 / ((Ftc * 1) + Fv + Ff);
	double st = 0;

	cout << "Введите [s]" << endl;
	cin >> st;

	if (s >= st)
	{
		cout << s << ">=" << st << "\tУсловие выполнено" << endl;
	}
	else { cout << "Условие не выполнено" << endl; }


}










int main()
{
	setlocale(LC_ALL, "RU");


	double F = 10.9 * pow(10, 3); //натяжение ветвей ленты конвейера 18         /8 for dauren/
	int q, q1, q2, q3, q4; // q1...q3 - выбор, n - запомнить полный тип редуктора
	double V = 1.3, DiamBar = 0.32; // скорость конвейера и диаметра барабана  1.3, 0.35 /1.6,0.32 for dau/
	double Pb, Ptreb, wB, nB;
	double ettaMuf, etta1, etta2, etta3, etta;



	cout << "Выберите тип передачи редуктора: 1 - зубчатая, 2 - червячная" << endl;
	cin >> q1;
	cin.ignore(32767, '\n');

	if (q1 == 2)
	{
		cout << "извините, кода еще нет,выберите другой тип" << endl;
		return 0;
	}

	cout << "Выберите тип зубчатых колес:";
	cout << "1 - цилиндрический, 2 - конический, 3 - червячный" << endl;

	cin >> q2;
	cin.ignore(32767, '\n');
	if (q2 == 3)
	{
		cout << "извините, кода еще нет,выберите другой тип" << endl;
		return 0;
	}


	cout << "Выберите тип колес: 1 - прямозубые, 2 - косозубые" << endl;
	cin >> q3;
	cin.ignore(32767, '\n');

	if (q1 == 1 && q2 == 1 && q3 == 1)
	{
		cout << "Ваш редуктор - прямозубый с цилиндрическими зубчатами колесами" << endl;
		q = 1;
	}
	if (q1 == 1 && q2 == 1 && q3 == 2)
	{
		cout << "Ваш редуктор - косозубый с цилиндрическими зубчатами колесами" << endl;
		q = 2;
	}
	if (q1 == 1 && q2 == 2 && q3 == 1)
	{
		cout << "Ваш редуктор - прямозубый с коническими зубчатами колесами" << endl;
		q = 3;
	}
	if (q1 == 1 && q2 == 2 && q3 == 2)
	{
		cout << "Ваш редуктор - косозубый с коническими зубчатами колесами" << endl;
		q = 4;
	}
	cout << endl;

	cout << "Выберите тип передачи:1 - цепная, 2 - клиноременная, 3 - плоскоременная" << endl;
	cin >> q4;

	cout << "Введите КПД муфты" << endl;
	cin >> ettaMuf;

	cout << "Введите КПД цилиндрической (конической) передачи с зубчатами колесами" << endl;
	cin >> etta1;

	cout << "Введите КПД передачи(цепная,клиноременная...)" << endl;
	cin >> etta2;

	cout << "Введите КПД, учитывающий потери в паре подшипников" << endl;
	cin >> etta3;

	etta = ettaMuf * etta1 * etta2 * pow(etta3, 3); //общий КПД привода
	etta = Round3(etta);
	cout << "Общий КПД привода - " << etta << endl;

	Pb = F * V; //мощность на валу барабана
	Ptreb = Pb / etta; //требуемая мощность ЭД
	wB = 2 * V / DiamBar; //угловая скорость барабана
	nB = 30 * wB / 3.14;// частота вращения барабана


	cout << "Мощность на валу барабана\n Pb = " << Pb << endl;
	cout << "Угловая скорость барабана\n Wb = " << wB << "\n"
		<< "Частота вращения барабана\n Nb =  " << nB << endl << endl;

	cout << "требуемая мощность ЭД\n Pтр(T) = " << Ptreb << endl << endl;

	// Выбираем ЭД, пока что все от руки


	int nSyn; double s; // синхронная частота вращения и скольжение
	cout << "Введите синхронную частоту вращения и скольжение(%)" << endl;
	cin >> nSyn >> s;

	int nDv; double wDv; //частота вращения вала двигателя и угловая скорость
	nDv = nSyn * (1 - (s / 100));
	cout << "Номинальная частота вращения - " << nDv << endl;
	wDv = 3.14 * nDv / 30;
	cout << "Угловая скорость - " << wDv << endl;

	double i, uTSP;
	i = wDv / wB; // общее передаточное отношение привода
	cout << "Oбщее передаточное отношение привода - " << i << endl;

	double uRed;
	cout << "Введите частные передаточные отношения редуктора" << endl;
	cin >> uRed; // 2.5 для конических прямозубых (<3) ГОСТ 2185-66


	uTSP = i / uRed; //частное пер. отн. для цеп.пер. 
	cout << "Частное передаточное отношение для цепной передачи - " << uTSP << endl;

	double n2, n3, w1, w2, w3, P1, P2, P3, T1, T2, T3; int n1;
	n1 = nDv; w1 = wDv; // Вал В
	n1 = Round3(n1); w1 = Round3(w1);
	n2 = n1 / uRed; w2 = w1 / uRed; // Вал С
	n2 = Round3(n2); w2 = Round3(w2);
	n3 = n2 / uTSP; w3 = w2 / uTSP; // Вал А
	n3 = Round3(n3); w3 = Round3(w3);

	cout << "Вал В n1 = " << n1 << "\t\t" << "Вал С n2 = " << n2 << "\t\t" << "Вал А n3 = " << n3 << endl;
	cout << "Вал В w1 = " << w1 << "\t\t" << "Вал С w2 = " << w2 << "\t\t" << "Вал А w3 = " << w3 << endl << endl;

	P1 = Ptreb * ettaMuf * etta3;
	P2 = Ptreb * ettaMuf * etta3 * etta3 * etta2;
	P3 = Ptreb * etta;
	P1 = Round3(P1);
	P2 = Round3(P2);
	P3 = Round3(P3);
	cout << "P1(Вал 1) = " << P1 << "\t\t" << "P2(Вал 2) = " << P2 << "\t\t"
		<< "P3(Вал 3) = " << P3 << endl << endl;

	T1 = Round3(P1 / w1); T2 = Round3(P2 / w2); T3 = Round3(P3 / w3);
	cout << "T1(Вал 1)(Н*мм) = " << T1 << "*10^3" << "\t\t" << "T2(Вал 2) = " << T2 << "*10^3" << "\t\t"
		<< "T3(Вал 3) = " << T3 << "*10^3" << endl << endl;

	cout << "РАСЧЕТ ЗУБЧАТЫХ КОЛЕС РЕДУКТОРА" << endl << endl;

	int64_t HB1, HB2; double kHL, sH, sigmH, sigmH1, sigmH2, kHB, psiBA,
		u, kA, aW, mn, betta;
	int AW; double z1, z2, cosB, d1, d2, da1, da2, Vo, b2, b1, kH, psiBD, kHA, kHV;

	double sigmaH, sigmaF1, Ft, Fr, Fa, kFB, kFV, kF,
		zv1, zv2, yf1, yf2, yb, sigmOHlimb1, sigmOHlimb2, sf, sf1, sf2, sigmf1, sigmf2, kfa, sigmaF2;

	double qwe, eps, n;

	if ((q3 == 1 || q3 == 2) && q2 == 1)
	{
		cout << "Введите твердость шестерни HB" << endl;
		cin >> HB1;
		cout << "Введите твердость шестерни колеса" << endl;
		cin >> HB2;
		cout << "Введите коэффициент долговечности kHL, коэф. безопасности sH" << endl;
		cin >> kHL >> sH;

		sigmH1 = Round3((2 * HB1 + 70) * kHL / sH);
		cout << "Sigma H1(Mпа) - " << sigmH1 << endl;

		sigmH2 = Round3((2 * HB2 + 70) * kHL / sH);
		cout << "Sigma H2(Mпа) - " << sigmH2 << endl;

		sigmH = Round3(0.45 * (sigmH1 + sigmH2));
		cout << "Sigma H(Mпа) - " << sigmH << endl;

		if (sigmH <= 1.23 * sigmH2)
		{
			cout << sigmH << "<=" << sigmH2 << endl;
		}
		else { cout << "Условие не выполнено" << endl; }

		cout << "Введите kHB" << endl; cin >> kHB;
		cout << "Введите коэффициент ширины венца(psiBA)" << endl;
		cin >> psiBA;

		cout << "Введите Ка и u" << endl; cin >> kA >> u;

		qwe = (T2 * 1000 * kHB) / (sigmH * sigmH * u * u * psiBA);

		aW = kA * (u + 1) * pow(qwe, 0.333);

		cout << "Межосевое расстояние(мм)- " << aW << endl;
		cout << "Введите ближайшее значение по ГОСТ" << endl;

		cin >> AW;
		aW = AW;

		cout << "Введите стандартный окружной модуль зацепления mn" << endl;
		cin >> mn;

		double zSum;

		if (q == 2)
		{
			cout << "Введите угол наклона зубьев" << endl;
			cin >> betta;
			betta *= 3.14 / 180;


			z1 = 2 * aW * cos(betta) / ((u + 1) * mn);
			z2 = z1 * u;
			cout << "Числа зубьев шестерни - " << z1 << "\t" << "колеса - " << z2 << endl;

			cosB = (z1 + z2) * mn / (2 * aW);
			cout << "cosB - " << cosB << endl;

			cout << "Подберите угол B из таблицы и введите" << endl;
			cin >> betta;
		}
		else {
			cout << "Введите угол наклона зубьев" << endl;
			cin >> betta;


			zSum = 2 * aW / mn;
			cout << "zSumma = " << zSum << endl;

			z1 = zSum / (u + 1);
			z2 = zSum - z1;

			cout << "Числа зубьев шестерни - " << z1 << "\t" << "колеса - " << z2 << endl;

		}

		double aWtemp;
		aWtemp = 0.5 * (z1 + z2) * mn;
		cout << "проверка aW = " << aWtemp << endl;
		cout << aWtemp << "=" << aW << endl;

		cout << "Диаметры делительные (мм)" << endl;

		d1 = (mn * z1) / cos(betta * 3.14 / 180);
		d2 = (mn * z2) / cos(betta * 3.14 / 180);

		cout << "d1 = " << d1 << "\t" << "d2 = " << d2 << endl;
		cout << "Проверка aW=(d1+d2)/2 = " << (d1 + d2) / 2 << endl;

		cout << "Диаметры вершин зубьев (мм)" << endl;

		da1 = d1 + (2 * mn); da2 = d2 + (2 * mn);
		cout << "da1 = " << da1 << "\t" << "da2 = " << da2 << endl;

		cout << "Ширина колеса (мм)" << endl;
		b2 = psiBA * aW;
		b1 = b2 + 5;
		cout << "b1 = " << b1 << "\t" << "b2 = " << b2 << endl;

		cout << "Коэффициент ширины шестерни по диаметру (mm)" << endl;

		psiBD = b1 / d1;
		cout << "psiBD = " << psiBD << endl;

		cout << "Окружная скорость колес" << endl;
		Vo = (w1 * d1) / 2 * 1000;
		cout << "Vo = " << Vo << endl;

		cout << "Коэффициент нагрузки kH" << endl;
		cout << "Введите коэффициенты kHB,kHa,kHV" << endl;
		cin >> kHB >> kHA >> kHV;

		kH = kHB * kHA * kHV;
		cout << "kH - " << kH << endl;

		cout << "Проверка контактных напряжений" << endl;


		if (q3 == 2)
		{
			qwe = T2 * 1000 * kH * pow((u + 1), 3) / (b2 * u * u);
			sigmaH = (270 / aW) * pow(qwe, 0.5);
		}
		else
		{
			qwe = T2 * 1000 * kH * pow((u + 1), 3) / (b2 * u * u);
			sigmaH = (310 / aW) * pow(qwe, 0.5);
		}

		cout << "sigmaH = " << sigmaH << endl;
		if (sigmaH <= sigmH)
		{
			cout << sigmaH << "<=" << sigmH << endl;
		}
		else { cout << "Условие не выполнено" << endl; }

		cout << "Силы,действующие в зацеплении" << endl;

		Ft = 2 * T1 * 1000 / d1;
		cout << "Окружная Ft(H) = " << Ft << endl;
		Fr = Ft * tan(20 * 3.14 / 180) / cos(betta * 3.14 / 180);
		cout << "Радиальная Fr(H) = " << Fr << endl;
		Fa = Ft * tan(betta * 3.14 / 180);
		cout << "Осевая Fа(H) = " << Fa << endl;

		cout << "Проверка зубьев на выносливость по напряжениям" << endl << endl;
		cout << "Введите коэффициенты Kfb,Kfv" << endl;
		cin >> kFB >> kFV;

		kF = kFB * kFV;
		cout << "kF - " << kF << endl;
		zv1 = z1 / pow(cos(betta * 3.14 / 180), 3);
		zv2 = z2 / pow(cos(betta * 3.14 / 180), 3);

		cout << "zv1 = " << zv1 << "\t" << "zv2 = " << zv2 << endl;
		cout << "Введите Yf1,Yf2" << endl;
		cin >> yf1 >> yf2;

		cout << "Введите sigmaHlimb0 для шестерни и колеса" << endl;
		cin >> sigmOHlimb1 >> sigmOHlimb2;

		cout << "Введите sf' u sf''" << endl;
		cin >> sf1 >> sf2;
		sf = sf1 * sf2;
		cout << "Sf = " << sf << endl;


		cout << "Допускаемые напряжения" << endl;
		cout << "для шестерни\t";
		sigmf1 = sigmOHlimb1 / sf;
		cout << "sigmaF1 = " << sigmf1 << endl;
		cout << "для колеса\t";
		sigmf2 = sigmOHlimb2 / sf;

		cout << "sigmaF1/yf1 = " << sigmf1 / yf1 << endl;
		cout << "sigmaF2/yf2 = " << sigmf2 / yf2 << endl;

		yb = 1 - (betta / 140);
		cout << "YB = " << yb << endl;
		eps = 1.5, n = 8;
		kfa = (4 + ((eps - 1) * (n - 5))) / (4 * eps);

		cout << "kFa = " << kfa << endl;

		if (q3 == 2)
		{
			if (sigmf1 > sigmf2)
			{
				cout << "Прочность зуба колеса" << endl;



				sigmaF2 = (Ft * kF * yf2 * yb * kfa) / (b2 * mn);
				cout << "sigmaF2 = " << sigmaF2 << endl;
				if (sigmaF2 <= sigmf2)
				{
					cout << sigmaF2 << "<=" << sigmf2 << endl;
				}
				else { cout << "условие не выполнено" << endl; }

			}
			else
			{
				cout << "Прочность зуба шестерни" << endl;
				sigmaF1 = (Ft * kF * yf1 * yb * kfa) / b1 * mn;
				cout << "sigmaF1 = " << sigmaF1 << endl;
				if (sigmaF1 <= sigmf1)
				{
					cout << sigmaF1 << "<=" << sigmf1 << endl;
				}
				else { cout << "условие не выполнено" << endl; }
			}
		}
		else
		{
			cout << "Прочность зуба шестерни" << endl;
			if (sigmf1 > sigmf2)
			{
				cout << "Прочность зуба колеса" << endl;
				sigmaF2 = Ft * kF * yf2 / (b2 * mn);

				cout << "sigmaF2 = " << sigmaF2 << endl;
				if (sigmaF2 <= sigmf2)
				{
					cout << sigmaF2 << "<=" << sigmf2 << endl;
				}
				else { cout << "условие не выполнено" << endl; }

			}
			else
			{
				cout << "Прочность зуба шестерни" << endl;
				sigmaF1 = Ft * kF * yf1 / (b1 * mn);
				cout << "sigmaF1 = " << sigmaF1 << endl;
				if (sigmaF1 <= sigmf1)
				{
					cout << sigmaF1 << "<=" << sigmf1 << endl;
				}
				else { cout << "условие не выполнено" << endl; }
			}
			cout << "sigmaF1 = " << sigmaF1 << endl;
			if (sigmaF1 <= sigmf1)
			{
				cout << sigmaF1 << "<=" << sigmf1 << endl;
			}
			else { cout << "условие не выполнено" << endl; }
		}


		double z3 = 0, z4 = 0, Ke = 0,
			p = 0, pp = 0, t = 0, Q = 0, q = 0, Aon = 0, dd1 = 0, vc = 0, Ftc = 0,
			Lt = 0, at = 0, del = 0, Zsum = 0, ac = 0,
			Fv = 0, KF = 0, Ff = 0, FB = 0, dd3 = 0, De3 = 0, s = 0;


		cout << "ПРЕДВАРИТЕЛЬНЫЙ РАСЧЕТ ВАЛОВ РЕДУКТОРА" << endl;

		double dv1, dv2, dp1, dp2, dDv, dk1, dk2;


		dv1 = pow((16 * T1 * 1000) / (3.14 * 25), 0.33333333);
		cout << "Диаметр выходного конца ведущего вала dv1 = " << dv1 << endl;
		//10; 10,5; 11; 11,5; 12; 13; 14; 15; 16; 17; 18; 20: 21; 22; 24; 
		//25; 26; 28; 30; 32; 33; 34; 36; 38; 40; 42; 45; 48; 50; 52; 
		//55; 60; 63; 65; 70; 75; 80; 85; 90; 95; 100; 105; 110; 120; 125; 130
		cout << "Введите округленное значение по госту" << endl;
		cin >> dv1;//40
		cout << "Введите диаметр вала двигателя" << endl;
		cin >> dDv;//55
		dp1 = dv1 + 5;
		dk1 = dp1 - 10;
		cout << "Диаметр под подшипниками dn1 = " << dp1 << endl;
		cout << "Диаметр под шестерней dk1 = " << dk1 << endl;

		dv2 = pow((16 * T2 * 1000) / (3.14 * 20), 0.33333333);
		cout << "Диаметр выходного конца ведущего вала dv2 = " << dv2 << endl;

		cout << "Введите округленное значение по госту" << endl;
		cin >> dv2;//60
		dp2 = dv2 + 5;
		dk2 = dp2 + 5;
		cout << "Диаметр под подшипниками dn2 = " << dp2 << endl;
		cout << "Диаметр под колесом dk2 = " << dk2 << endl << endl;


		cout << "Конструктивные размеры шестерни и колеса" << endl;
		cout << "d1 = " << d1 << endl;
		cout << "dv1 = " << dv1 << endl;
		cout << "b1 = " << b1 << endl;

		cout << "Колесо кованое" << endl;
		cout << "d2 = " << d2 << "\t" << "da2 = " << da2 << "\t" << "b2 = " << b2 << endl;
		cout << "dст = " << 1.6 * dk2 << endl << endl;


		cout << "РАСЧЕТ ЦЕПНОЙ ПЕРЕДАЧИ" << endl;

		cepPer(q2, T2, T3, n2, w2, uTSP, z3, z4, Ke, p, pp, t, Q, q, Aon, dd1, vc, Ftc,
			Lt, at, del, Zsum, ac, Fv, KF, Ff, FB, dd3, De3, s);

	}
	else if (q3 == 1 || q3 == 2 && q2 == 2)
	{
		cout << "\n\n\nРАСЧЕТ ЗУБЧАТОЙ ПЕРЕДАЧИ\n\n" << endl;


		double de2, de1, Kd, psibRe;
		u = uRed;


		//Марка стали - 40X, термообработка - улучшение, диаметр заготовки - 120-160, свыше 160


		cout << "Введите твердость шестерни HB" << endl; //260
		cin >> HB1;
		cout << "Введите твердость шестерни колеса" << endl;//230
		cin >> HB2;
		cout << "Введите коэффициент долговечности kHL, коэф. безопасности sH" << endl;
		cin >> kHL >> sH; // 1,,,1.15





		sigmH1 = (2 * HB1 + 70) * kHL / sH;
		sigmH1 = round(sigmH1);
		cout << "Шестерня Sigma H1(Mпа) - " << sigmH1 << endl;

		sigmH2 = (2 * HB2 + 70) * kHL / sH;
		sigmH2 = round(sigmH2);
		cout << "Колесо Sigma H2(Mпа) - " << sigmH2 << endl;

		cout << "Введите коэффициент kHB при консольном расположении шестерни" << endl;
		cin >> kHB;//1.35

		cout <<
			"Введите коэффициент ширины венца по отношению к внешнему конусному расстоянию"
			<< endl;
		cin >> psibRe; //0.285 .... ГОСТ 12289-76


		if (q3 == 1)
		{
			cout << "Введите коэффициент Kd для прямозубых передач" << endl;
			cin >> Kd;//99
		}
		else if (q3 == 2)
		{
			cout << "Введите коэффициент Kd для косозубых передач" << endl;
			cin >> Kd;
		}

		double temp1, temp2, temp3;
		temp1 = T2 * 1000 * kHB * u;
		temp2 = 1 - (0.5 * psibRe);
		temp3 = sigmH2 * sigmH2 * pow(temp2, 2) * psibRe;


		de2 = Kd * pow(temp1 / temp3, 0.33333333);
		cout << "Внешний делительный диаметр de2 = " << de2 << endl;

		cout << "Введите ближайшее значение de2 по ГОСТ" << endl;
		//ГОСТ 12289 - 76 (в мм) : 50; (56); 63; (71); 80; (90); 100; (112); 125; 
		//(140); 160; (180); 200; (225) ; 250; 280; 315; 355; 400; 450; 
		//500; 560; 630; 710; 800; 900; 1000; 1120; 1250; 1400; 1600.

		cin >> de2;//355(ближайшее)


		cout << "Введите z1" << endl; //ГОСТ 13754—81
		cin >> z1;

		z2 = round(z1 * u);

		cout << "z2 = " << z2 << endl;
		double uTemp;
		uTemp = z2 / z1;
		cout << "u = " << uTemp << endl;
		cout << "Проверка отклонения " << (uTemp - u) * 100 / u << "%" << " < 3%" << endl;

		double me;
		me = de2 / z2;
		cout << "Внешний окружной модуль me = " << me << endl;

		cout << "Уточняем размер de2" << endl;
		double de2Temp;
		de2Temp = me * z2;
		de2Temp = Round3(de2Temp);

		cout << "de2 = " << de2Temp << endl;
		cout << (de2Temp - de2) * 100 / de2 << "% < " << "2%" << endl;

		double del1, minT, minT2, del2;

		cout << "Углы делительных конусов" << endl << endl;
		cout << "ctgdel1=u=" << u << endl;
		cout << "Введите угол delta1" << endl;//21
		cin >> del1;
		cout << "Введите минуты" << endl;//48
		cin >> minT;


		minT2 = 60 - minT;
		del2 = 89 - del1;

		del1 += (minT / 60);
		del2 += (minT2 / 60);

		cout << "Угол delta 1 - " << del1 << endl;
		cout << "Угол delta 2 - " << del2 << endl;

		del1 *= (3.14 / 180);
		//del1 = Round3(del1);
		del2 *= (3.14 / 180);
		//del2 = Round3(del2);
		double Re, b;

		Re = 0.5 * me * sqrt(pow(z1, 2) + pow(z2, 2));
		Re = round(Re);
		cout << "Внешнее конусное расстояние Re = " << Re << endl;

		b = psibRe * Re;
		b = ceil(b);

		cout << "Длина зуба b = " << b << endl;

		de1 = me * z1;
		de1 = ceil(me * z1);
		cout << "Внешний делительный диаметр шестерни  de1 = " << de1 << endl;

		d1 = 2 * (Re - (0.5 * b)) * sin(del1);
		d1 = Round3(d1);
		cout << "Средний делительный диаметр шестерни d1 = " << d1 << endl;

		double dae1, dae2, tmpDel;
		dae1 = de1 + (2 * me * Round3(cos(del1)));
		dae2 = de2 + (2 * me * Round3(cos(del2)));
		dae1 = ceil(dae1);
		dae2 = ceil(dae2);

		cout << "Внешние диаметры шестерни и колеса" << endl;
		cout << "dae1 = " << dae1 << "\t" << "dae2 = " << dae2 << endl;

		double m;

		m = d1 / z1;
		cout << "Средний окружной модуль m = " << m << endl;

		psiBD = Round3(b / d1);

		cout << "Коэффициент ширины шестерни по среднему диаметру psiBD =" << psiBD << endl;

		V = Round3((w1 * d1) / (2000));

		cout << "Средняя окружная скорость колес V(м/c) = " << V << endl; // 8 степень точности
		if (V <= 5)
		{
			cout << "Примем 7-ю степень точности" << endl;
		}
		else if (V >= 5 && V <= 7)
		{
			cout << "Примем 8-ю степень точности" << endl;
		}
		cout << "Введите коэффициент, учитывающий распределение нагрузки по длине зуба kHB" << endl;
		cin >> kHB;//1.18
		cout << "Введите коэффициент, учитывающий распределение нагрузки между прямыми зубьями kHа" << endl;
		cin >> kHA;//1
		cout << "Введите коэффициент, учитывающий динамическую нагрузку в зацеплении kHV" << endl;
		cin >> kHV;//1.3

		kH = kHB * kHA * kHV;
		cout << "Коэффициент твердости kH = " << kH << endl;


		temp1 = Re - (0.5 * b);
		temp2 = T2 * 1000 * kH;
		temp3 = pow(((u * u) + 1), 0.66666667);

		sigmaH = (335 / temp1) * pow((temp2 * temp3 / (b * u * u)), 0.5);
		cout << "Проверяем контактное напряжение sigmaH = " << sigmaH << endl;

		if (sigmaH <= sigmH2)
		{
			cout << sigmaH << " <= " << sigmH2 << endl;
		}
		else
		{
			cout << "Условие не выполнилось" << endl;
		}


		Ft = 2 * T1 * 1000 / d1;
		cout << "Окружная сила Ft(Н) = " << Ft << endl;
		double Fr1, Fr2, Fa2, Fa1, alp;

		alp = 20 * 3.14 / 180; // угол профиля производящего (режущего) инструмента - 20

		Fr1 = Ft * tan(alp) * cos(del1);
		Fa2 = Fr1;
		Fr2 = Ft * tan(alp) * sin(del1);
		Fa1 = Fr2;
		cout << "Радиальная сила для шестерни,равная осевой для колеса:" << endl;
		cout << "Fr1=Fa2 = " << Fr1 << endl;
		cout << "Fa1=Fr2 = " << Fr2 << endl;

		cout << "Введите коэффициенты kFB,kFV" << endl; //1.38, 1.45
		cin >> kFB >> kFV;
		kF = kFB * kFV;
		cout << "Коэффициент нагрузки kF = " << kF << endl;

		zv1 = z1 / cos(del1);
		zv1 = round(zv1);
		zv2 = z2 / cos(del2);
		zv2 = round(zv2);

		cout << "Эквивалентные числа зубьев\nzv1 = " << zv1 << endl;
		cout << "zv2 = " << zv2 << endl;

		cout << "Введите YF1 YF2" << endl; //3.82,3.6
		cin >> yf1 >> yf2;

		sigmOHlimb1 = 1.8 * HB1;
		sigmOHlimb1 = round(sigmOHlimb1);
		sigmOHlimb2 = 1.8 * HB2;
		sigmOHlimb2 = round(sigmOHlimb2);

		cout << "Введите sf' u sf''" << endl;
		cin >> sf1 >> sf2; //1.75,1
		sf = sf1 * sf2;
		cout << "Sf = " << sf << endl;


		cout << "Допускаемые напряжения" << endl;
		cout << "для шестерни\t";
		sigmf1 = sigmOHlimb1 / sf;
		cout << "sigmaF1 = " << sigmf1 << endl;
		cout << "для колеса\t";
		sigmf2 = sigmOHlimb2 / sf;
		cout << "sigmaF2 = " << sigmf2 << endl;

		cout << "Отношение для шестерни sigmaF1/yf1 = " << sigmf1 / yf1 << endl;
		cout << "для колеса sigmaF2/yf2 = " << sigmf2 / yf2 << endl;

		if ((sigmf1 / yf1) > (sigmf2 / yf2))
		{
			cout << "Прочность зуба колеса" << endl;

			sigmaF2 = (Ft * kF * yf2) / (0.85 * b * m);
			cout << "sigmaF2 = " << sigmaF2 << endl;
			if (sigmaF2 <= sigmf2)
			{
				cout << sigmaF2 << "<=" << sigmf2 << endl;
			}
			else { cout << "условие не выполнено" << endl; }
		}
		else
		{
			cout << "Прочность зуба шестерни" << endl;

			sigmaF1 = (Ft * kF * yf1) / 0.85 * b * m;
			cout << "sigmaF1 = " << sigmaF1 << endl;
			if (sigmaF1 <= sigmf1)
			{
				cout << sigmaF1 << "<=" << sigmf1 << endl;
			}
			else { cout << "условие не выполнено" << endl; }
		}


		cout << endl << endl;
		cout << "ПРЕДВАРИТЕЛЬНЫЙ РАСЧЕТ ВАЛОВ РЕДУКТОРА" << endl;

		double dv1, dv2, dp1, dp2, dDv, dk1, dk2;


		dv1 = pow((T1 * 1000) / (0.2 * 15), 0.33333333);
		cout << "Диаметр выходного конца ведущего вала dv1 = " << dv1 << endl;
		//10; 10,5; 11; 11,5; 12; 13; 14; 15; 16; 17; 18; 20: 21; 22; 24; 
		//25; 26; 28; 30; 32; 33; 34; 36; 38; 40; 42; 45; 48; 50; 52; 
		//55; 60; 63; 65; 70; 75; 80; 85; 90; 95; 100; 105; 110; 120; 125; 130
		cout << "Введите округленное значение по госту" << endl;
		cin >> dv1;//40
		cout << "Введите диаметр вала двигателя" << endl;
		cin >> dDv;//55
		dp1 = dv1 + 5;
		dk1 = dp1 + 6;
		cout << "Диаметр под подшипниками dn1 = " << dp1 << endl;
		cout << "Диаметр под шестерней dk1 = " << dk1 << endl;

		dv2 = pow((T2 * 1000) / (0.2 * 20), 0.33333333);
		cout << "Диаметр выходного конца ведущего вала dv2 = " << dv2 << endl;

		cout << "Введите округленное значение по госту" << endl;
		cin >> dv2;//60
		dp2 = dv2 + 5;
		dk2 = dp2 + 6;
		cout << "Диаметр под подшипниками dn2 = " << dp2 << endl;
		cout << "Диаметр под колесом dk2 = " << dk2 << endl << endl;




		cout << "КОНСТРУКТИВНЫЕ РАЗМЕРЫ ШЕСТЕРНИ И КОЛЕСА" << endl;

		double hae, hfe, he, tanOa, tanOf, Oa, Of, dela1, dela2, delf1, delf2;

		hae = me;
		hfe = 1.2 * me;

		he = hae + hfe;

		cout << "hae = " << hae << "\t" << "hfe = " << hfe << "\t" << "he = " << he << endl;

		tanOa = round((hae / Re) * 10000) / 10000;
		cout << "tanOa = " << tanOa << endl;
		cout << "Введите угол Өа" << endl;
		cin >> Oa; //1.6897

		tanOf = round((hfe / Re) * 10000) / 10000;
		cout << "tanOf = " << tanOf << endl;
		cout << "Введите угол Өf" << endl;
		cin >> Of;//2.0274

		del1 *= 180 / 3.14;
		del2 *= 180 / 3.14;

		dela1 = del1 + Oa;
		cout << "dela1 = " << dela1 << endl;
		delf1 = del1 - Of;
		cout << "delf1 = " << delf1 << endl;



		double z3 = 0, z4 = 0, Ke = 0,
			p = 0, t = 0, Q = 0, q = 0, Aon = 0, dd1 = 0, vc = 0, Ftc = 0, pTmp = 0,
			Lt = 0, at = 0, del = 0, Zsum = 0, ac = 0,
			Fv = 0, KF = 0, Ff = 0, FB = 0, dd3 = 0, De3 = 0, s = 0;

		cout << "РАСЧЕТ ЦЕПНОЙ ПЕРЕДАЧИ" << endl;

		cepPer(q2, T2, T3, n2, w2, uTSP, z3, z4, Ke, p, t, Q, q,
			Aon, dd1, vc, Ftc, pTmp, Lt, at, del, Zsum, ac, Fv, KF, Ff, FB, dd3, De3, s);


	}
}



