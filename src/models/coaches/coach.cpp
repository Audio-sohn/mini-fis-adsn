#include "coach.h"

#include <iostream>

Coach::Coach()
{
}

void Coach::addCeilingDisplay(Display const& display)
{
    this->ceiling_displays.push_back(display);
}

void Coach::addSeatDisplay(std::string const& seatId, Display const& display)
{
    // tupel aus key value einfügen
    this->seat_displays.insert({seatId, display});
}

void Coach::updateCeilingDisplays(std::string const& newText)
{
    // witchtig das einzelne element per referenz (&) aufzurufen
    // nur so wird das member in place verändert
    for (auto &disp : ceiling_displays) 
    {
        disp.updateText(newText); 
    }
}

void Coach::updateSeatDisplay(std::string const& seatId, std::string const& newText)
{
    for (auto &[id, text] : seat_displays)
    {
        if (id == seatId)
        {
            text = newText;
        }

    }
}

void Coach::showCeilingDisplays() const
{
    std::cout << "=============== SHOWING CEILING DISPLAYS ===============\n" << std::endl;

    for (auto cdisp : this->ceiling_displays) 
    {
        std::cout << cdisp.getText() << std::endl;

    }
}

void Coach::showSeatDisplays() const
{

    std::cout << "=============== SHOWING SEAT DISPLAYS ===============\n" << std::endl;

    for (auto sdisp : seat_displays) 
    {
        std::cout << "Id: " << sdisp.first << " Content: " << sdisp.second.getText() << std::endl;
    }
}

void Coach::showAllDisplays() const
{
    showSeatDisplays();
    showCeilingDisplays();
}
