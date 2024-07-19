#include <cmath>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "../MathUtils/MathUtils.h"

class Color {
public:
	/**
	* @brief Constructor of the Color class.
	*
	* Creates a color object with 0.0.
	*
	*/

	Color();

	/**
    * @brief Constructor of the Color class.
    *
    * Creates a color object with the specified components.
    *
    * @param r Red color component (0.0 to 255.0f).
    * @param g Green color component (0.0 to 255.0f).
    * @param b Blue color component (0.0 to 255.0f).
    */

	Color(float r, float g, float b);

	/**
	* @brief Constructor of the Color class.
	*
	* Creates a color object with the specified components.
	*
	* @param value passes the value.
	* @param rgba If true, the format will be in rgba, and if false, in rgb.
	*/

	Color(int value, bool rgba);

	/**
	* @brief Constructor of the Color class.
	*
	* Creates a color object with the specified components.
	*
	* @param hex creating a color using hex format.
	*/

	Color(std::string hex);

	/**
	* @brief Constructor of the Color class.
	*
	* Creates a color object with the specified components.
	*
	* @param h Hue color component (0 to 360).
	* @param s Saturation color component (0 to 100).
	* @param l Lightness color component (0 to 100).
	*/
	Color(int h, int s, int l);


	/**
    * @brief Constructor of the Color class.
    *
    * Creates a color object with the specified components.
    *
    * @param r Red color component (0.0 to 255.0f).
    * @param g Green color component (0.0 to 255.0f).
    * @param b Blue color component (0.0 to 255.0f).
    * @param a Alpha color channel (0.0 to 255.0f).
    */

	Color(float r, float g, float b, float a);

	/*
	* @brief Get the color in RGB format.
	* @returns We get the color in RGB format (red, green, blue).
	*/
	int getRGB() const;

	/* 
	* @brief Get the color in RGBA format.
    * @returns We get the color in RGBA format (red, green, blue, alpha).
	*/
	int getRGBA() const;

	/* 
	* @brief Get the red component of the color.
    * @returns We get the red component of the color (in the range 0.0f - 255.0f).
	*/
	float getRed() const;

	/*
	* @brief Get the red component of the color.
	* @returns We get the red component of the color (in the range 0.0f - 1.0f).
	*/

	float getNormalizedRed() const;

	/* 
	* @brief Get the green component of the color.
	* @returns We get the green component of the color (in the range 0.0f - 255.0f).
	*/

	float getGreen() const;

	/*
	* @brief Get the green component of the color.
	* @returns We get the green component of the color (in the range 0.0f - 1.0f).
	*/

	float getNormalizedGreen() const;

    /* 
	* @brief Get the blue component of the color.
    * @returns We get the blue component of the color (in the range 0.0f - 255.0f).
	*/
	float getBlue() const;

	/* 
	* @brief Get the blue component of the color.
    * @returns We get the blue component of the color (in the range 0.0f - 1.0f).
	*/

	float getNormalizedBlue() const;

   
    /* 
	* @brief Get the Alpha channel of the color.
    * @returns We get the Alpha channel (in the range from 0.0 to 255.0f).
	*/
	float getAlpha() const;

	/* 
	* @brief Get the Alpha channel of the color.
    * @returns We get the Alpha channel (in the range from 0.0 to 1.0f).
	*/

	float getNormalizedAlpha() const;

	/*
	* @brief Setting the red color value.
	*/
	void setRed(float r);

	/*
	* @brief Setting the green color value.
	*/
	void setGreen(float g);

	/*
	* @brief Setting the blue color value.
	*/
	void setBlue(float b);

	/*
	* @brief Setting the alpha channel color value.
	*/
	void setAlpha(float a);

	/*
	* @brief Setting the color in hex format.
	*/
    void setHex(std::string hex);

	/*
	* @brief Setting the color in rgb format (red,green,blue).
	*/

    void setRGB(int rgb) ;

	/*
	* @brief Setting the color in rgba format (red,green,blue,alpha).
	*/
    void setRGBA(int rgba);

	/*
	* @brief Setting the color in hsl format.
	* @param h Hue color component (0 to 360f).
	* @param s Saturation color component (0 to 100f).
	* @param l Lightness color component (0 to 100f).
	*/
	void setHSL( int h,  int s,  int l);


private:
	float red, green, blue, alpha;
};