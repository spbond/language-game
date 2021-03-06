/*Copywrite 2014 Shaun Bond, Jeffery Waldon, Charlie Carlson, Simon Smith, Joseph DeWilde, Aaron Andrews*/

/*This file is part of Dina'ki Adventures.

Dina'ki Adventures is free software : you can redistribute it and / or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Dina'ki Adventures is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Dina'ki Adventures. If not, see <http://www.gnu.org/licenses/>.*/

// ProfileWrangler for profilewrangler object
// Created by Charlie Carlson
// Scrum 1: Feb 18th 2014

// There will be one of these objects that will be owned by the "game"
// This class will be respnosible for loading all profiles from files
// it will also be responsible for saving profiles to file and removing profiles.

#ifndef __PROFILEWRANGLER_H__
#define __PROFILEWRANGLER_H__

//#include <cstdlib>
//using std::free;

#include "profile.h"

#include <string>
#include <vector>

#include <cereal/archives/binary.hpp>
#include <SFML\System\String.hpp>
#include <windows.h>
#include <shlobj.h>

class ProfileWrangler
{
public:
    
    ProfileWrangler();

    // loads profile from file and returns current list of profiles
    // idea is that the game should always be in a state where you want to
    // load from file to get most updated list of profiles
    std::vector< std::shared_ptr<Profile> > loadProfiles(std::string fileName = "profilelist");
    
    std::vector< std::shared_ptr<Profile> > getProfiles();
    
    // adds profile, can add profile possible created before hand
    // or make a copy of a profile pased to it so it is handled
    // in the correct shared ptr format
    void addProfile(std::shared_ptr<Profile>);
    void addProfile(Profile);
    
    // removes profile. Must be handed shared ptr from vector
    // which can be gotten via loadprofiles
    // will call save profiles, hence removing the proflie for ever!
    void removeProfile(std::shared_ptr<Profile>);
    
    void removeProfile();
    
    // saves profiles to file
    void saveProfiles(std::string fileName = "profilelist") const;
    
    void setCurrentProfile(int index);
    
    std::shared_ptr<Profile> getCurrentProfile();
    
private:
    std::vector< std::shared_ptr<Profile> > m_profiles;
    
	int m_curr_profile_index;
	std::string m_DocumentsPath;        // Used to get the user's Document file path
};


#endif /* end define for __PROFILEWRANGLER_H__ */
