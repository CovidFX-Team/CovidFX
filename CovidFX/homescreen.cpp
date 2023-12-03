#include "homescreen.h"
#include "ui_homescreen.h"
#include "country.h"
#include <iostream>

void createDataPoints(QVector<Country> countries, QVector<double> &x, QVector<double> &y, double &xAxisMax, double &yAxisMax);
void loadCountryData(QVector<Country> &countries);


homescreen::homescreen(QWidget *parent) : QDialog(parent), ui(new Ui::homescreen) {
    ui->setupUi(this);

    QVector<Country> countries; // stores objects of Country class
    QVector<double> x; // stores data of GDP per capita
    QVector<double> y; // stores data of deaths per million
    double xAxisMax = 100;
    double yAxisMax = 100;

    loadCountryData(countries);
    createDataPoints(countries, x, y, xAxisMax, yAxisMax);

    // add country names to drop down menu
    ui->countryDropDownMenu->addItem("");
    for (auto it : countries) {
        QString countryNameQString = QString::fromStdString(it.getName());
        ui->countryDropDownMenu->addItem(countryNameQString);
    }


    // ui->comboBox_2->addItem("GDP Per Capita");
    // ui->comboBox_2->addItem("Total Cases Per Million");
    // ui->comboBox_2->addItem("Total Deaths Per Million");
    // ui->comboBox_2->addItem("Total Deaths Per Case");

    ui->dataPlot->addGraph(ui->dataPlot->xAxis, ui->dataPlot->yAxis);
    ui->dataPlot->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->dataPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->dataPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    ui->dataPlot->graph(0)->setName("A Country");

    // sets the data for the graph
    ui->dataPlot->graph(0)->setData(x, y);

    // sets the range for each axis to be appropriate
    ui->dataPlot->xAxis->setRange(0, xAxisMax * 1.05);
    ui->dataPlot->yAxis->setRange(0, yAxisMax * 1.05);

    std::cout << "Xaxis max: " << xAxisMax << std::endl;
    std::cout << "Yaxis max: " << yAxisMax << std::endl;

    // add title layout element
    ui->dataPlot->plotLayout()->insertRow(0);
    ui->dataPlot->plotLayout()->addElement(0, 0, new QCPTextElement(ui->dataPlot, "Total confirmed Covid-19 deaths per million vs GDP per capita", QFont("sans", 12, QFont::Bold)));

    // set axis labels
    ui->dataPlot->xAxis->setLabel("GDP per capita");
    ui->dataPlot->yAxis->setLabel("Confirmed Covid-19 deaths per million");
}


homescreen::~homescreen() {
    delete ui;
}


// creates data points to plot on the graph from country data
void createDataPoints(QVector<Country> countries, QVector<double> &x, QVector<double> &y, double &xAxisMax, double &yAxisMax) {
    for (int i = 0; i < countries.size(); i++) {
        double xValue = static_cast<double>(countries[i].getGDP());
        double yValue = static_cast<double>(countries[i].getDeaths());

        if (xValue > xAxisMax) {
            xAxisMax = xValue;
        }
        if (yValue > yAxisMax) {
            yAxisMax = yValue;
        }

        x.push_back(xValue);
        y.push_back(yValue);
        std::cout << xValue << ", " << yValue << std::endl;
    }
}


// populates QVector with relevant data
// country name, gdp, total cases per million, total deaths per million
void loadCountryData(QVector<Country> &countries) {
    Country Albania("Albania",18552,117541,1268);
	Country Algeria("Algeria",13210,6056,153);
	Country Angola("Angola",6974,2978,54);
	Country AntiguaAndBarbuda("Antigua and Barbuda",25337,97108,1557);
	Country Argentina("Argentina",26505,220930,2867);
	Country Armenia("Armenia",18942,161963,3151);
	Country Australia("Australia",62625,443823,886);
	Country Austria("Austria",67936,680263,2521);
	Country Azerbaijan("Azerbaijan",17764,80473,998);
	Country Bahamas("Bahamas",40379,92890,2059);
	Country Bahrain("Bahrain",61228,473167,1043);
	Country Bangladesh("Bangladesh",7395,11951,172);
	Country Barbados("Barbados",17837,390824,2201);
	Country Belarus("Belarus",22591,104252,747);
	Country Belgium("Belgium",65027,413283,2946);
	Country Belize("Belize",11451,175333,1698);
	Country Benin("Benin",4056,2100,12);
	Country Bolivia("Bolivia",9684,98910,1833);
	Country BosniaAndHerzegovina("Bosnia and Herzegovina",20377,124694,5059);
	Country Botswana("Botswana",18323,125574,1065);
	Country Brazil("Brazil",17822,175195,3273);
	Country Brunei("Brunei",69275,694663,363);
	Country Bulgaria("Bulgaria",33582,192008,5664);
	Country BurkinaFaso("Burkina Faso",2546,973,17);
	Country Burundi("Burundi",836,4218,1);
	Country CaboVerde("Cabo Verde",9083,108572,700);
	Country Cambodia("Cambodia",5349,8286,182);
	Country Cameroon("Cameroon",4408,4481,71);
	Country Canada("Canada",58400,122644,1386);
	Country CentralAfricanRepublic("Central African Republic",967,2754,20);
	Country Chad("Chad",1668,434,11);
	Country Chile("Chile",30209,269788,3143);
	Country China("China",21476,69652,85);
	Country Colombia("Colombia",20287,123037,2756);
	Country Comoros("Comoros",3832,10886,191);
	Country Congo("Congo",3791,4220,65);
	Country CostaRica("Costa Rica",24923,239128,1820);
	Country CoteDIvoire("Côte d\'Ivoire",6538,3137,30);
	Country Croatia("Croatia",40380,316538,4559);
	Country Cyprus("Cyprus",49931,737555,1522);
	Country CzechRepublic("Czech Republic",49946,443833,4087);
	Country Denmark("Denmark",74005,580902,1500);
	Country Dominica("Dominica",13573,217131,1017);
	Country DominicanRepublic("Dominican Republic",22834,59407,390);
	Country DRCongo("DR Congo",1337,1002,15);
	Country Ecuador("Ecuador",12822,59393,2002);
	Country Egypt("Egypt",15091,4649,224);
	Country ElSalvador("El Salvador",11096,31849,668);
	Country EquatorialGuinea("Equatorial Guinea",17396,10227,109);
	Country Estonia("Estonia",46697,454116,2188);
	Country Eswatini("Eswatini",10782,62456,1188);
	Country Ethiopia("Ethiopia",2812,4061,61);
	Country Fiji("Fiji",14125,74263,952);
	Country Finland("Finland",59027,268392,1863);
	Country France("France",55493,603428,2599);
	Country Gabon("Gabon",16471,20507,129);
	Country Gambia("Gambia",2510,4666,137);
	Country Georgia("Georgia",20113,495486,4575);
	Country Germany("Germany",63150,461051,2099);
	Country Ghana("Ghana",6498,5128,44);
	Country Greece("Greece",36835,520535,3618);
	Country Grenada("Grenada",16987,156968,1897);
	Country Guatemala("Guatemala",10818,71233,1134);
	Country Guinea("Guinea",3187,2782,34);
	Country GuineaBissau("Guinea-Bissau",2190,4566,84);
	Country Guyana("Guyana",40642,90745,1606);
	Country Haiti("Haiti",3305,2967,74);
	Country Honduras("Honduras",6741,45490,1067);
	Country Hungary("Hungary",41907,221521,4898);
	Country Iceland("Iceland",69081,560848,499);
	Country India("India",8379,31753,375);
	Country Indonesia("Indonesia",14653,24731,588);
	Country Iran("Iran",18075,86052,1654);
	Country Iraq("Iraq",10862,55410,570);
	Country Ireland("Ireland",126905,342924,1842);
	Country Israel("Israel",49509,512299,1344);
	Country Italy("Italy",51865,443251,3252);
	Country Jamaica("Jamaica",11822,55321,1277);
	Country Japan("Japan",45573,272716,603);
	Country Jordan("Jordan",11003,154795,1251);
	Country Kazakhstan("Kazakhstan",30810,77475,983);
	Country Kenya("Kenya",5764,6367,105);
	Country Kiribati("Kiribati",2365,38747,183);
	Country Kuwait("Kuwait",58056,156114,602);
	Country Kyrgyzstan("Kyrgyzstan",6133,13406,154);
	Country Laos("Laos",9384,29069,89);
	Country Latvia("Latvia",39956,527552,3990);
	Country Lesotho("Lesotho",2695,15542,307);
	Country Liberia("Liberia",1725,1495,55);
	Country Libya("Libya",23375,74463,945);
	Country Lithuania("Lithuania",48397,484800,3534);
	Country Luxembourg("Luxembourg",142214,593541,1544);
	Country Madagascar("Madagascar",1774,2308,48);
	Country Malawi("Malawi",1732,4361,132);
	Country Malaysia("Malaysia",33434,151182,1096);
	Country Maldives("Maldives",24772,356424,603);
	Country Mali("Mali",2517,1468,33);
	Country Malta("Malta",55928,225808,1654);
	Country MarshallIslands("Marshall Islands",7228,387998,409);
	Country Mauritania("Mauritania",6424,13465,211);
	Country Mauritius("Mauritius",26906,238493,811);
	Country Mexico("Mexico",21512,60331,2625);
	Country Micronesia("Micronesia",3855,232505,569);
	Country Moldova("Moldova",15238,191003,3705);
	Country Mongolia("Mongolia",14230,297545,672);
	Country Montenegro("Montenegro",26984,400713,4232);
	Country Morocco("Morocco",9519,34094,435);
	Country Mozambique("Mozambique",1468,7087,68);
	Country Myanmar("Myanmar",4870,11837,360);
	Country Namibia("Namibia",11206,67051,1597);
	Country Nepal("Nepal",4725,32849,394);
	Country Netherlands("Netherlands",69577,490709,1309);
	Country NewZealand("New Zealand",51967,461069,651);
	Country Nicaragua("Nicaragua",6875,2310,35);
	Country Niger("Niger",1505,363,12);
	Country Nigeria("Nigeria",5860,1222,14);
	Country NorthMacedonia("North Macedonia",20162,166748,4751);
	Country Norway("Norway",114899,274084,1055);
	Country Oman("Oman",41724,87286,1011);
	Country Pakistan("Pakistan",6437,6703,130);
	Country Panama("Panama",39280,237624,1963);
	Country PapuaNewGuinea("Papua New Guinea",4447,4621,66);
	Country Paraguay("Paraguay",15977,108527,2946);
	Country Peru("Peru",15048,132769,6511);
	Country Philippines("Philippines",10133,35616,577);
	Country Poland("Poland",43269,163719,3002);
	Country Portugal("Portugal",41452,547278,2670);
	Country Qatar("Qatar",114648,190909,256);
	Country Romania("Romania",41888,176919,3480);
	Country Russia("Russia",36485,159363,2765);
	Country Rwanda("Rwanda",2792,9668,107);
	Country SaintKittsAndNevis("Saint Kitts & Nevis",34052,138567,965);
	Country SaintLucia("Saint Lucia",17756,167603,2279);
	Country Samoa("Samoa",6041,75444,139);
	Country SaoTomeAndPrincipe("Sao Tome & Principe",4738,29020,352);
	Country SaudiArabia("Saudi Arabia",59065,23112,265);
	Country Senegal("Senegal",4209,5141,114);
	Country Serbia("Serbia",23911,372554,2628);
	Country Seychelles("Seychelles",35228,475447,1605);
	Country SierraLeone("Sierra Leone",1931,902,15);
	Country Singapore("Singapore",127565,465919,332);
	Country Slovakia("Slovakia",37459,330940,3751);
	Country Slovenia("Slovenia",50032,634662,4457);
	Country SolomonIslands("Solomon Islands",2654,29838,211);
	Country SouthAfrica("South Africa",15905,67996,1713);
	Country SouthKorea("South Korea",50070,667207,693);
	Country Spain("Spain",45825,293960,2562);
	Country SriLanka("Sri Lanka",14405,30807,773);
	Country StVincentAndGrenadines("St. Vincent & Grenadines",17207,92767,1193);
	Country StateOfPalestine("State of Palestine",6757,133946,1087);
	Country Sudan("Sudan",4216,1365,108);
	Country Suriname("Suriname",17620,133628,2278);
	Country Sweden("Sweden",64578,257687,2361);
	Country Switzerland("Switzerland",83598,505199,1609);
	Country Tajikistan("Tajikistan",4885,1787,13);
	Country Tanzania("Tanzania",3097,658,13);
	Country Thailand("Thailand",20672,66359,481);
	Country TimorLeste("Timor-Leste",4828,17491,103);
	Country Togo("Togo",2608,4467,33);
	Country TrinidadAndTobago("Trinidad and Tobago",27778,125076,2867);
	Country Tunisia("Tunisia",12490,93343,2381);
	Country Turkey("Turkey",37274,199255,1188);
	Country Tuvalu("Tuvalu",5421,259638,88);
	Country Uganda("Uganda",2694,3638,77);
	Country Ukraine("Ukraine",12671,139049,2769);
	Country UnitedArabEmirates("United Arab Emirates",87729,113019,249);
	Country UnitedKingdom("United Kingdom",54603,367050,3413);
	Country UnitedStates("United States",76399,305764,3361);
	Country Uruguay("Uruguay",28842,303623,2230);
	Country Uzbekistan("Uzbekistan",9533,5028,29);
	Country Vanuatu("Vanuatu",3289,36784,43);
	Country Vietnam("Vietnam",13457,118386,440);
	Country Zambia("Zambia",3894,17449,203);
	Country Zimbabwe("Zimbabwe",2531,16287,350);

    countries.push_back(Albania);
    countries.push_back(Algeria);
    countries.push_back(Angola);
    countries.push_back(AntiguaAndBarbuda);
    countries.push_back(Argentina);
    countries.push_back(Armenia);
    countries.push_back(Australia);
    countries.push_back(Austria);
    countries.push_back(Azerbaijan);
    countries.push_back(Bahamas);
    countries.push_back(Bahrain);
    countries.push_back(Bangladesh);
    countries.push_back(Barbados);
    countries.push_back(Belarus);
    countries.push_back(Belgium);
    countries.push_back(Belize);
    countries.push_back(Benin);
    countries.push_back(Bolivia);
    countries.push_back(BosniaAndHerzegovina);
    countries.push_back(Botswana);
    countries.push_back(Brazil);
    countries.push_back(Brunei);
    countries.push_back(Bulgaria);
    countries.push_back(BurkinaFaso);
    countries.push_back(Burundi);
    countries.push_back(CaboVerde);
    countries.push_back(Cambodia);
    countries.push_back(Cameroon);
    countries.push_back(Canada);
    countries.push_back(CentralAfricanRepublic);
    countries.push_back(Chad);
    countries.push_back(Chile);
    countries.push_back(China);
    countries.push_back(Colombia);
    countries.push_back(Comoros);
    countries.push_back(Congo);
    countries.push_back(CostaRica);
    countries.push_back(CoteDIvoire);
    countries.push_back(Croatia);
    countries.push_back(Cyprus);
    countries.push_back(CzechRepublic);
    countries.push_back(Denmark);
    countries.push_back(Dominica);
    countries.push_back(DominicanRepublic);
    countries.push_back(DRCongo);
    countries.push_back(Ecuador);
    countries.push_back(Egypt);
    countries.push_back(ElSalvador);
    countries.push_back(EquatorialGuinea);
    countries.push_back(Estonia);
    countries.push_back(Eswatini);
    countries.push_back(Ethiopia);
    countries.push_back(Fiji);
    countries.push_back(Finland);
    countries.push_back(France);
    countries.push_back(Gabon);
    countries.push_back(Gambia);
    countries.push_back(Georgia);
    countries.push_back(Germany);
    countries.push_back(Ghana);
    countries.push_back(Greece);
    countries.push_back(Grenada);
    countries.push_back(Guatemala);
    countries.push_back(Guinea);
    countries.push_back(GuineaBissau);
    countries.push_back(Guyana);
    countries.push_back(Haiti);
    countries.push_back(Honduras);
    countries.push_back(Hungary);
    countries.push_back(Iceland);
    countries.push_back(India);
    countries.push_back(Indonesia);
    countries.push_back(Iran);
    countries.push_back(Iraq);
    countries.push_back(Ireland);
    countries.push_back(Israel);
    countries.push_back(Italy);
    countries.push_back(Jamaica);
    countries.push_back(Japan);
    countries.push_back(Jordan);
    countries.push_back(Kazakhstan);
    countries.push_back(Kenya);
    countries.push_back(Kiribati);
    countries.push_back(Kuwait);
    countries.push_back(Kyrgyzstan);
    countries.push_back(Laos);
    countries.push_back(Latvia);
    countries.push_back(Lesotho);
    countries.push_back(Liberia);
    countries.push_back(Libya);
    countries.push_back(Lithuania);
    countries.push_back(Luxembourg);
    countries.push_back(Madagascar);
    countries.push_back(Malawi);
    countries.push_back(Malaysia);
    countries.push_back(Maldives);
    countries.push_back(Mali);
    countries.push_back(Malta);
    countries.push_back(MarshallIslands);
    countries.push_back(Mauritania);
    countries.push_back(Mauritius);
    countries.push_back(Mexico);
    countries.push_back(Micronesia);
    countries.push_back(Moldova);
    countries.push_back(Mongolia);
    countries.push_back(Montenegro);
    countries.push_back(Morocco);
    countries.push_back(Mozambique);
    countries.push_back(Myanmar);
    countries.push_back(Namibia);
    countries.push_back(Nepal);
    countries.push_back(Netherlands);
    countries.push_back(NewZealand);
    countries.push_back(Nicaragua);
    countries.push_back(Niger);
    countries.push_back(Nigeria);
    countries.push_back(NorthMacedonia);
    countries.push_back(Norway);
    countries.push_back(Oman);
    countries.push_back(Pakistan);
    countries.push_back(Panama);
    countries.push_back(PapuaNewGuinea);
    countries.push_back(Paraguay);
    countries.push_back(Peru);
    countries.push_back(Philippines);
    countries.push_back(Poland);
    countries.push_back(Portugal);
    countries.push_back(Qatar);
    countries.push_back(Romania);
    countries.push_back(Russia);
    countries.push_back(Rwanda);
    countries.push_back(SaintKittsAndNevis);
    countries.push_back(SaintLucia);
    countries.push_back(Samoa);
    countries.push_back(SaoTomeAndPrincipe);
    countries.push_back(SaudiArabia);
    countries.push_back(Senegal);
    countries.push_back(Serbia);
    countries.push_back(Seychelles);
    countries.push_back(SierraLeone);
    countries.push_back(Singapore);
    countries.push_back(Slovakia);
    countries.push_back(Slovenia);
    countries.push_back(SolomonIslands);
    countries.push_back(SouthAfrica);
    countries.push_back(SouthKorea);
    countries.push_back(Spain);
    countries.push_back(SriLanka);
    countries.push_back(StVincentAndGrenadines);
    countries.push_back(StateOfPalestine);
    countries.push_back(Sudan);
    countries.push_back(Suriname);
    countries.push_back(Sweden);
    countries.push_back(Switzerland);
    countries.push_back(Tajikistan);
    countries.push_back(Tanzania);
    countries.push_back(Thailand);
    countries.push_back(TimorLeste);
    countries.push_back(Togo);
    countries.push_back(TrinidadAndTobago);
    countries.push_back(Tunisia);
    countries.push_back(Turkey);
    countries.push_back(Tuvalu);
    countries.push_back(Uganda);
    countries.push_back(Ukraine);
    countries.push_back(UnitedArabEmirates);
    countries.push_back(UnitedKingdom);
    countries.push_back(UnitedStates);
    countries.push_back(Uruguay);
    countries.push_back(Uzbekistan);
    countries.push_back(Vanuatu);
    countries.push_back(Vietnam);
    countries.push_back(Zambia);
    countries.push_back(Zimbabwe);
}
