#include <cmath>
#include <string>
#include <iostream>
#include <sstream>

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
	* @param rgb creating a color using rgb format.
	*/

	Color(int rgb);

	/**
	* @brief Constructor of the Color class.
	*
	* Creates a color object with the specified components.
	*
	* @param rgba creating a color using rgba format.
	*/

	Color(unsigned int rgba);

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
	* @param h Hue color component (0.0 to 360.0f).
	* @param s Saturation color component (0.0 to 100.0f).
	* @param l Lightness color component (0.0 to 100.0f).
	*/
	Color(float h, float s, float l);


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
	* @brief Get the green component of the color.
	* @returns We get the green component of the color (in the range 0.0f - 255.0f).
	*/
	float getGreen() const;

    /* 
	* @brief Get the blue component of the color.
    * @returns We get the blue component of the color (in the range 0.0f - 255.0f).
	*/
	float getBlue() const;

   
    /* 
	* @brief Get the Alpha channel of the color.
    * @returns We get the Alpha channel (in the range from 0.0 to 255.0f).
	*/
	float getAlpha() const;



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
	* @param h Hue color component (0.0 to 360.0f).
	* @param s Saturation color component (0.0 to 100.0f).
	* @param l Lightness color component (0.0 to 100.0f).
	*/
	void setHSL(float h, float s, float l);

private:
	float red, green, blue, alpha;
};