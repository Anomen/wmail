/*
 * This file is part of WMail.
 * Copyright (C) 2010-2011  Kevin Vicrey <kevin.vicrey@nexu.org>
 * Copyright (C) 2010-2011  Cyril Collen <cyril.collen@nexu.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "CMenu.h"

#include <Wt/WTreeTableNode>

using namespace Wt;
using namespace nsWMail;

CMenu::CMenu() 
    : WTreeTable()
{
    resize(350, 300);
    
    // Create and set the root node
    WTreeTableNode *root = new WTreeTableNode("All Personnel");
    root->setImagePack("resources/");
    setTreeRoot(root, "Emweb Organigram");
    
    // Populate the tree with data nodes.
    WTreeTableNode *node1 = new WTreeTableNode("Upper Management", 0, root);
    WTreeTableNode *node2;
    node2 = new WTreeTableNode("Chief Anything Officer", 0, node1);
    node2 = new WTreeTableNode("Vice President of Parties", 0, node1);
    root->expand();
}

CMenu::~CMenu() { }
