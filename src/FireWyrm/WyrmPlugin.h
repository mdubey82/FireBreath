/**********************************************************\
 Original Author: Richard Bateman (taxilian)

 Created:    Jan 19, 2015
 License:    Dual license model; choose one of two:
             New BSD License
             http://www.opensource.org/licenses/bsd-license.php
             - or -
             GNU Lesser General Public License, version 2.1
             http://www.gnu.org/licenses/lgpl-2.1.html

 Copyright 2015 Richard Bateman, Firebreath development team
\**********************************************************/

#pragma once
#ifndef H_FB_FIREWYRM_FIREWYRMPLUGIN
#define H_FB_FIREWYRM_FIREWYRMPLUGIN

#include "WyrmBrowserHost.h"
#include "WyrmJSObject.h"
#include "BrowserPlugin.h"

namespace FB {
    FB_FORWARD_PTR(BrowserStream);

    namespace FireWyrm {

    struct PluginCreateError : std::runtime_error
    {
        PluginCreateError(const std::string& error)
          : std::runtime_error(error)
        { }
    };

    FB_FORWARD_PTR(FireWyrmPlugin);

    class FireWyrmPlugin : public FB::BrowserPlugin
    {
    public:
        FireWyrmPlugin(const FireWyrmBrowserHostPtr& host, const std::string& mimetype);
        virtual ~FireWyrmPlugin(void);

        virtual void init(const std::string& name);
        virtual void shutdown();

        virtual bool setReady();

    protected:
        NPJavascriptObject *m_obj;
        FireWyrmBrowserHostPtr m_npHost;
        bool m_retainReturnedNPObject;
        bool m_isReady;
        std::string m_mimetype;
        std::string m_pluginName;
        std::string m_pluginDesc;
    };

}; }; // FB::FireWyrm

#endif // H_FB_FIREWYRM_FIREWYRMPLUGIN

