/*  error.cc - this file is part of MediaTomb.
                                                                                
    Copyright (C) 2005 Gena Batyan <bgeradz@deadlock.dhs.org>,
                       Sergey Bostandzhyan <jin@deadlock.dhs.org>
                                                                                
    MediaTomb is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
                                                                                
    MediaTomb is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
                                                                                
    You should have received a copy of the GNU General Public License
    along with MediaTomb; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "common.h"
#include "pages.h"
#include "tools.h"
#include "mxml/mxml.h"

using namespace zmm;
using namespace mxml;

#include "string_converter.h"

web::error::error() : WebRequestHandler()
{}

void web::error::process()
{
    String message = param(_("message"));

    Ref<Element> root (new Element(_("root")));
    
    String validMessagePart = StringConverter::validSubstring(message, _("UTF-8"));
    
    root->appendTextChild(_("display"), _("An error has occured. Press Back in your browser to return to the previous page."));
    root->appendTextChild(_("error"), validMessagePart);
    *out << renderXMLHeader(_("/error.xsl"));
    *out << root->print();
}
