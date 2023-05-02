//
// Created by Alexander Winter on 2023-01-07.
//

#ifndef LD52_CLIENT_MATHUTIL_H
#define LD52_CLIENT_MATHUTIL_H

#include <string>
#include <sstream>
#include "SFML/System/Vector2.hpp"

namespace wiz {
    /**
     * Converts specified integer vector to a float vector
     * 
     * @param intVec integer vector 
     * @return float vector with the same value
     */
	inline sf::Vector2f toFloat(sf::Vector2i intVec) {
		return sf::Vector2f { static_cast<float>(intVec.x), static_cast<float>(intVec.y) };
	}
    
    /**
     * Converts specified unsigned integer vector to a float vector
     * 
     * @param intVec unsigned integer vector
     * @return float vector with the same value
     */
	inline sf::Vector2f toFloat(sf::Vector2u intVec) {
		return sf::Vector2f { static_cast<float>(intVec.x), static_cast<float>(intVec.y) };
	}

    /**
     * Returns the square of its input
     * @param x input
     * @return square of x
     */
	inline constexpr const float pow2(float x) {
		return x * x;
	}

    /**
     * Returns the hexadecimal representation of the specified number
     * 
     * @param number number to get hex representation 
     * @return string containing hex representation
     */
	inline std::string toHexString(int number) {
		std::stringstream stream;
		stream << std::hex << number;
		return stream.str();
	}

    /**
     * Checks if two line segments intersect. The line segments are defined from
     * p0 to p1 and p2 to p3.
     * 
     * @param p0 start of the first segment
     * @param p1 end of the first segment
     * @param p2 start of the second segment
     * @param p3 end of the second segment
     * @return true if they intersect, otherwise false
     */
    bool segmentsIntersect(sf::Vector2f p0, sf::Vector2f p1,
                           sf::Vector2f p2, sf::Vector2f p3);

    /**
     * Computes the squared distance between a point and a line segment
     * 
     * @param point 
     * @param lineStart 
     * @param lineEnd 
     * @return distance
     */
    float pointSegmentDistanceSquared(sf::Vector2f point, 
                                      sf::Vector2f lineStart, 
                                      sf::Vector2f lineEnd);

    /**
     * Computes the distance between a point and a line segment
     * 
     * @param point 
     * @param lineStart 
     * @param lineEnd 
     * @return distance
     */
    float pointSegmentDistance(sf::Vector2f point, 
                               sf::Vector2f lineStart, 
                               sf::Vector2f lineEnd);
}

#endif //LD52_CLIENT_MATHUTIL_H
