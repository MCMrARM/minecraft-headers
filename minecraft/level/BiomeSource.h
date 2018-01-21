#pragma once

enum class GeneratorType;

class BiomeSource {

public:
    char filler[0x50];

    BiomeSource(unsigned int, GeneratorType);

};