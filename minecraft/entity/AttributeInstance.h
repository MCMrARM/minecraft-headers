#pragma once

class AttributeInstance {

public:
    float getMaxValue() const;
    void serializationSetValue(float, int, float);
    void resetToMinValue();
    void resetToMaxValue();

};