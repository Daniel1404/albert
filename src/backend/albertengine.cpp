// albert - a simple application launcher for linux
// Copyright (C) 2014 Manuel Schneider
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "albertengine.h"
#include "fileindex/fileindex.h"
#include "applicationindex/applicationindex.h"
#include <iostream>

AlbertEngine* AlbertEngine::_instance = nullptr;

/**********************************************************************//**
 * @brief AlbertEngine::AlbertEngine
 * @param parent
 */
AlbertEngine::AlbertEngine()
{
	// _websearch =
	// _calculator =
//_indizes.push_back(FileIndex::instance());
	_indizes.push_back(ApplicationIndex::instance());
}

/**********************************************************************//**
 * @brief AlbertEngine::~AlbertEngine
 */
AlbertEngine::~AlbertEngine()
{
}

/**********************************************************************//**
 * @brief AlbertEngine::instance
 * @return
 */
AlbertEngine *AlbertEngine::instance(){
	if (_instance == nullptr)
		_instance = new AlbertEngine;
	return _instance;
}

/**********************************************************************//**
 * @brief AlbertEngine::request
 * @param req
 * @return
 */
void AlbertEngine::query(const std::string &req, std::vector<AbstractServiceProvider::AbstractItem*> *res)
{
	for (auto i: _indizes)
		i->query(req, res);

	std::cout << "Search finished. Found " << _result.size() << " items." << std::endl;
}

/**********************************************************************//**
 * @brief AlbertEngine::buildIndex
 */
void AlbertEngine::buildIndex()
{
	for (auto i: _indizes) {
		i->buildIndex();
	}
}