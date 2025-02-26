//
// Created by smmm on 03.03.2025.
//

#ifndef OOP_REPLACE_H
#define OOP_REPLACE_H

#include <string>
#include <vector>
#include <map>



void ReplaceInStream(const ReplaceConfig& config, std::istream& inStream, std::ostream& outStream);
void ReplaceInLine(const ReplaceConfig& config, std::string& line);

#endif // OOP_REPLACE_H
