#include "Data.hpp"
#include <vector>
#include <iostream>
Data::Data(std::string NAME , std::string HTML){
	name = NAME;
	html = HTML;
	fillData();
}
Data::Data(std::string NAME, double LOW, double HIGH,double CHG, double PCHG , bool POS){
     name=name;
     low=LOW;
     high = HIGH;
     current= CURRENT;
     chg= CHG;
     pChg=PCHG;
     notACompany= POS;
}
void Data::fillData(){
    const int OUT_OF_RANGE = 100000;
    std::string changePlace = "yfs_c63_" + name;
    std::string pChangePlace = "yfs_pp0_" + name;
    std::string lowPlace = "yfs_g53_" + name;
    std::string highPlace = "yfs_h53_" + name;
    std::string currentPlace ="yfs_184_" + name;
    
    size_t addingSize = changePlace.size() + 2;
    
    size_t indexChg =html.find(changePlace) + addingSize;
    size_t indexPChg =html.find(pchangePlace) + addingSize;
    size_t indexLow =html.find(lowPlace) + addingSize;
    size_t indexHigh =html.find(highPlace) + addingSize;
    size_t indexCurrent =html.find(currentPlace) + addingSize;
    size_t indexSign = indexChg - 1;
    if (indexChg > OUT_OF_RANGE || indexPChg > OUT_OF_RANGE || indexLow > OUT_OF_RANGE || indexHigh > OUT_OF_RANGE || indexCurrent > OUT_OF_RANGE){
        std::cout << name << "introuvable" <<std::endl;
        notACompany = true;
        return;
    }
    std::string changS = html.substr(indexChg +1,6);
    std::string pchangS = html.substr(indexPChg +1,6);
    std::string lowS = html.substr(indexLow,6);
    std::string highS = html.substr(indexHigh,6);
    std::string currentS = html.substr(indexCurrent,6);
    std::string sign= html.substr(indexSign,1);
    
    chg = std::stod(changeS);
    pChg = std::stod(pChangeS);
    current = std::stod(currentS);
    high =std::stod(highS);
    low = std::stod(lowS);
    
    if (sign=="+"){
        positive = true;
    } else {
        positive = false;
    }
}
void Data::printData(){
     std::cout <<"\n"<< name <<":" << std::endl;
     std::cout <<"\tCURRENT\t\t"<<current <<"\n\tLOW\t\t\t"<<low <<"\n\tHIGH\t\t"<<high<<"\n\tCHANGE\t\t"<<chg<<"\n\t%CHANGE\t\t" << pChg << std::endl;
}
