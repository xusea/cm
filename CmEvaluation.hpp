//
//  CmEvaluation.hpp
//  testCM
//
//  Created by xusea on 16/1/17.
//  Copyright © 2016年 xusea. All rights reserved.
//

#ifndef CmEvaluation_hpp
#define CmEvaluation_hpp
#include "cmdefine.h"
#include <string>
using namespace std;
struct CmEvaluation
{
    // Save the precision recall curve, ROC curve, AUC, MaxFMeasure, MeanFMeasure and MAE to a Matlab file for direct ploting
    static void Evaluate(CStr gtW, CStr &salDir, CStr &resName, vecS &des);
    static void Evaluate(CStr gtW, CStr &salDir, CStr &resName, CStr &des) {vecS descri(1); descri[0] = des; Evaluate(gtW, salDir, resName, descri);}
    
    // Plot the FMeasure bar
    static void EvalueMask(CStr gtW, CStr &maskDir, vecS &des, CStr resFile, double betaSqr = 0.3, bool alertNul = false, CStr suffix = "", CStr title = "");
    static void EvalueMask(CStr gtW, CStr &maskDir, CStr &des, CStr resFile, double betaSqr = 0.3, bool alertNul = false, CStr suffix = "");
    
public: // Assistant functions
    
    static void MeanAbsoluteError(CStr inDir, CStr salDir, vecS des, bool zeroMapIfMissing = false);
    
    static double FMeasure(CMat &mask1u, CMat &gtMask1u); // The two mask should contain values of either 0 or 255.
    // Format change from OpenCV region (x, y, width, height) to VOC bounding box (minx, minY, maxX, maxY)
    static inline Vec4i reg2Box(const Rect &reg) {return Vec4i(reg.x, reg.y, reg.x + reg.width - 1, reg.y + reg.height - 1);}
    
    static double interUnionBBox(const Vec4i &box1, const Vec4i &box2); // each box minx, minY, maxX, maxY
    static double interUnionBBox(const Rect &reg1, const Rect &reg2) {return interUnionBBox(reg2Box(reg1), reg2Box(reg2));}
    
    static int STEP; // Evaluation threshold density
    static void PrintVector(FILE *f, const vecD &v, std::string name);
    
protected:
    static const int COLOR_NUM = 255;
    static const int NUM_THRESHOLD;  // Number of difference threshold
    
    // Return mean absolute error (MAE)
    static double Evaluate_(std::string gtImgW, std::string inDir, std::string resExt, vecD &precision, vecD &recall, vecD &tpr, vecD &fpr);
};

#endif /* CmEvaluation_hpp */
