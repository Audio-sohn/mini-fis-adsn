#include "vehicle.h"
#include <iostream>
#include <algorithm>

Vehicle::Vehicle()
    : next_stop("")
{
}

void Vehicle::addCoach(Coach const& coach)
{
    this->coaches.push_back(coach);
    this->reservations.push_back({});
}

void Vehicle::addStop(std::string const& stop)
{
    route.push_back(stop);
}

void Vehicle::addReservation(size_t coachIndex, std::string const& seatId, Reservation const& reservation)
{
    // check if stop order is right
    // reservation stops and starts should be in route
    // start should be BEFORE stop

    if (reservation.from == reservation.to) 
    {
        return;
    }

    int startPos = -1; 
    int endPos = -1;

    // iterate through route and find the reservations
    for (size_t i = 0; i < route.size(); i++) 
    {
        if (route[i] == reservation.from)
        {    
            startPos = static_cast<int>(i);
        }

        if (route[i] == reservation.to)
        {
            endPos = static_cast<int>(i);
        }

        // check if reservation stops are not being found
        // check if reservation.to is before reservation.from
        if ((startPos > endPos) || startPos == -1 || endPos == -1) 
        {
            // add seat to reservations but leave reservations empty
            reservations[coachIndex].insert({seatId, {}});
            return;
        }

    }


    // if all is well, then add reservation
    reservations[coachIndex].insert({seatId, {reservation}});
}

void Vehicle::showAllDisplays() const
{
    for (auto coach : coaches)
    {   
        coach.showAllDisplays();
    }
}

void Vehicle::showAllReservations() const
{
    for (auto const &coach : reservations)
    {
        
        for (auto const &[id, seatreservations] : coach) 
        {
            for (auto const &res : seatreservations)
            {
                res.getDisplayText();
            }
        }
    }
}

void Vehicle::setCurrentStop(size_t pos)
{   
    // check if stop out of range
    if (pos >= this->route.size())
    {
        this->next_stop = "";
        return;
    }

    // if in range, just set the next stop
    this->next_stop = route[pos];
}

void Vehicle::arriveAtStop()
{
    /// Ankunft an einer Station.
    /// Akualisiert die Displays und schaltet next_stop weiter.
    
    // aktualisiere die ceiling displays mit current stop(= ja NOCH next stop)
    for (auto &coach : coaches)
    {
        coach.updateCeilingDisplays(next_stop);
    }

    // lokalisiere nächsten stop und setze ihn

    for (size_t i = 0; i+1 < route.size(); i++)
    {
        if (route[i] == next_stop) 
        {
            next_stop = route[i+1];
        }
    }

}

void Vehicle::departFromStop()
{
    /// Abfahrt von einer Station.
    /// Aktualisiert die Displays.
    
    // ceiling displays auf: "nächster Halt : <next_stop>"
    for (auto &coach : coaches)
    {
        coach.updateCeilingDisplays("Nächster Halt: " + next_stop);
    }
}

void Vehicle::updateSeatDisplays()
{
    // update all seat displays with reservations



}
