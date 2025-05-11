//
// Created by smmm on 11.05.2025.
//

#ifndef SHAPEREADER_H
#define SHAPEREADER_H
#include <memory>
#include <shape/Shape.h>

class ShapeReader
{
public:
	std::shared_ptr<Shape> ReadShape(std::istream& is);
	std::vector<std::shared_ptr<Shape>> ReadShapes(std::istream& is);

private:
	[[nodiscard]] ShapeType ParseShapeType(const std::string& typeStr) const;
};

#endif // SHAPEREADER_H
