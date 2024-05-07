#pragma once

class header
{
    char* nume;
    float mate, eng, ist, average;
public:
    void setNume(const char* newName);
    const char* getNume();
    void setMate(float nota);
    void setEng(float nota);
    void setIst(float nota);
    float getMate();
    float getEng();
    float getIst();
    void setAverage();
    float getAverage();
};
