// Main.h
#ifndef _MAIN_H_
#define _MAIN_H_

class SmallIcons
{

public:
    explicit SmallIcons(); // DLL_ATTACH (входа)
    virtual ~SmallIcons(); // DLL_DETACH (выхода)
} SmallIcons; // class Main

#endif // !_MAIN_H_#pragma once
