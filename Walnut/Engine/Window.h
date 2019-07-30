#pragma once
#include<wlpch.h>
#include "common.h"
#include "Core.h"

struct WindowProperty
{
	unsigned int m_height;
	unsigned int m_Width;
	std::string m_Title;
	WindowProperty(const std::string& title = "Progress", unsigned int height = 1280, unsigned int width = 800) :
		m_Title(title),m_height(height), m_Width(width) 
	{}	
};


class WALNUT_API Window 
{
	//update
	//Create
	//Constructor
	//Destructor

};