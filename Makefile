#
# This file is part of WMail.
# Copyright (C) 2010-2011  Kevin Vicrey <kevin.vicrey@nexu.org>
# Copyright (C) 2010-2011  Cyril Collen <cyril.collen@nexu.org>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

all:
	cd build && cmake .. && make

run:
	build/source/wmail.wt --http-address vickev.fr --http-port 8080 --docroot web

clean:
	cd build && make clean && rm -rf build/*
