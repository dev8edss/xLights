#include "DMXEffect.h"
#include "DMXPanel.h"

#include "../sequencer/Effect.h"
#include "../RenderBuffer.h"
#include "../UtilClasses.h"

#include "../xLightsMain.h" //xLightsFrame

#include "../../include/dmx-16.xpm"
#include "../../include/dmx-24.xpm"
#include "../../include/dmx-32.xpm"
#include "../../include/dmx-48.xpm"
#include "../../include/dmx-64.xpm"


DMXEffect::DMXEffect(int id) : RenderableEffect(id, "DMX", dmx_16, dmx_24, dmx_32, dmx_48, dmx_64)
{
    //ctor
}

DMXEffect::~DMXEffect()
{
    //dtor
}

wxPanel *DMXEffect::CreatePanel(wxWindow *parent) {
    return new DMXPanel(parent);
}

static int GetPct(wxString val)
{
    int value = wxAtoi(val);
    return (value * 100) / 255;
}

void DMXEffect::adjustSettings(const std::string &version, Effect *effect)
{
    // give the base class a chance to adjust any settings
    if (RenderableEffect::needToAdjustSettings(version))
    {
        RenderableEffect::adjustSettings(version, effect);
    }

    SettingsMap &settings = effect->GetSettings();

    if (IsVersionOlder("2016.39", version))
    {
        if (settings.GetBool("E_CHECKBOX_Use_Dmx_Ramps")) {
            settings["E_VALUECURVE_DMX1"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMX1|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|", GetPct(settings["E_SLIDER_DMX1"]), GetPct(settings["E_SLIDER_DMX1_Ramp"]));
            settings["E_VALUECURVE_DMX2"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMX2|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|", GetPct(settings["E_SLIDER_DMX2"]), GetPct(settings["E_SLIDER_DMX2_Ramp"]));
            settings["E_VALUECURVE_DMX3"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMX3|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|", GetPct(settings["E_SLIDER_DMX3"]), GetPct(settings["E_SLIDER_DMX3_Ramp"]));
            settings["E_VALUECURVE_DMX4"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMX4|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|", GetPct(settings["E_SLIDER_DMX4"]), GetPct(settings["E_SLIDER_DMX4_Ramp"]));
            settings["E_VALUECURVE_DMX5"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMX5|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|", GetPct(settings["E_SLIDER_DMX5"]), GetPct(settings["E_SLIDER_DMX5_Ramp"]));
            settings["E_VALUECURVE_DMX6"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMX6|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|", GetPct(settings["E_SLIDER_DMX6"]), GetPct(settings["E_SLIDER_DMX6_Ramp"]));
            settings["E_VALUECURVE_DMX7"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMX7|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|", GetPct(settings["E_SLIDER_DMX7"]), GetPct(settings["E_SLIDER_DMX7_Ramp"]));
            settings["E_VALUECURVE_DMX8"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMX8|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|", GetPct(settings["E_SLIDER_DMX8"]), GetPct(settings["E_SLIDER_DMX8_Ramp"]));
            settings["E_VALUECURVE_DMX9"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMX9|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|", GetPct(settings["E_SLIDER_DMX9"]), GetPct(settings["E_SLIDER_DMX9_Ramp"]));
            settings["E_VALUECURVE_DMX10"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMX10|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|", GetPct(settings["E_SLIDER_DMX10"]), GetPct(settings["E_SLIDER_DMX10_Ramp"]));
            settings["E_VALUECURVE_DMX11"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMX11|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|", GetPct(settings["E_SLIDER_DMX11"]), GetPct(settings["E_SLIDER_DMX11_Ramp"]));
            settings["E_VALUECURVE_DMX12"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMX12|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|", GetPct(settings["E_SLIDER_DMX12"]), GetPct(settings["E_SLIDER_DMX12_Ramp"]));
            settings["E_VALUECURVE_DMX13"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMX13|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|", GetPct(settings["E_SLIDER_DMX13"]), GetPct(settings["E_SLIDER_DMX13_Ramp"]));
            settings["E_VALUECURVE_DMX14"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMX14|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|", GetPct(settings["E_SLIDER_DMX14"]), GetPct(settings["E_SLIDER_DMX14_Ramp"]));
            settings["E_VALUECURVE_DMX15"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMX15|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|", GetPct(settings["E_SLIDER_DMX15"]), GetPct(settings["E_SLIDER_DMX15_Ramp"]));
            settings["E_VALUECURVE_DMX16"] = "Active=TRUE|Id=ID_VALUECURVE_DMX16|Type=Ramp|Min=0.00|Max=255.00|P1=0|P2=0|";
            settings["E_VALUECURVE_DMX17"] = "Active=TRUE|Id=ID_VALUECURVE_DMX17|Type=Ramp|Min=0.00|Max=255.00|P1=0|P2=0|";
            settings["E_VALUECURVE_DMX18"] = "Active=TRUE|Id=ID_VALUECURVE_DMX18|Type=Ramp|Min=0.00|Max=255.00|P1=0|P2=0|";
            settings.erase("E_SLIDER_DMX1");
            settings.erase("E_SLIDER_DMX2");
            settings.erase("E_SLIDER_DMX3");
            settings.erase("E_SLIDER_DMX4");
            settings.erase("E_SLIDER_DMX5");
            settings.erase("E_SLIDER_DMX6");
            settings.erase("E_SLIDER_DMX7");
            settings.erase("E_SLIDER_DMX8");
            settings.erase("E_SLIDER_DMX9");
            settings.erase("E_SLIDER_DMX10");
            settings.erase("E_SLIDER_DMX11");
            settings.erase("E_SLIDER_DMX12");
            settings.erase("E_SLIDER_DMX13");
            settings.erase("E_SLIDER_DMX14");
            settings.erase("E_SLIDER_DMX15");
        } else {
            settings["E_SLIDER_DMX16"] = "0";
            settings["E_SLIDER_DMX17"] = "0";
            settings["E_SLIDER_DMX18"] = "0";
        }
        settings.erase("E_CHECKBOX_Use_Dmx_Ramps");
        settings.erase("E_SLIDER_DMX1_Ramp");
        settings.erase("E_SLIDER_DMX2_Ramp");
        settings.erase("E_SLIDER_DMX3_Ramp");
        settings.erase("E_SLIDER_DMX4_Ramp");
        settings.erase("E_SLIDER_DMX5_Ramp");
        settings.erase("E_SLIDER_DMX6_Ramp");
        settings.erase("E_SLIDER_DMX7_Ramp");
        settings.erase("E_SLIDER_DMX8_Ramp");
        settings.erase("E_SLIDER_DMX9_Ramp");
        settings.erase("E_SLIDER_DMX10_Ramp");
        settings.erase("E_SLIDER_DMX11_Ramp");
        settings.erase("E_SLIDER_DMX12_Ramp");
        settings.erase("E_SLIDER_DMX13_Ramp");
        settings.erase("E_SLIDER_DMX14_Ramp");
        settings.erase("E_SLIDER_DMX15_Ramp");
    }
}

bool DMXEffect::SetDMXSinglColorPixel(int chan, int num_channels, const SettingsMap &SettingsMap, double eff_pos, xlColor& color, RenderBuffer &buffer)
{
    if( num_channels >= chan ) {
        wxString name = wxString::Format("DMX%d", chan);
        int value = GetValueCurveInt(name, 0, SettingsMap, eff_pos);
        color.red = value;
        color.green = value;
        color.blue = value;
        buffer.SetPixel(chan-1, 0, color);
        return false;
    } else {
        return true;
    }
}

void DMXEffect::SetColorBasedOnStringType(int value, int slot, xlColor& color, const std::string& string_type)
{
    const char which_color = string_type[slot-1];
    if( which_color == 'R' ) {
        color.red = value;
    } else if( which_color == 'G' ) {
        color.green = value;
    } else if( which_color == 'B' ) {
        color.blue = value;
    }
}

bool DMXEffect::SetDMXRGBNode(int node, int num_channels, const SettingsMap &SettingsMap, double eff_pos, xlColor& color, RenderBuffer &buffer, const std::string& string_type)
{
    bool return_val = false;
    color = xlBLACK;
    int base_chan = ((node-1)*3+1);
    if( num_channels >= base_chan || buffer.BufferWi < node) {
        wxString name = wxString::Format("DMX%d", base_chan);
        int value = GetValueCurveInt(name, 0, SettingsMap, eff_pos);
        SetColorBasedOnStringType(value, 1, color, string_type);
        if( num_channels >= base_chan+1 ) {
            name = wxString::Format("DMX%d", base_chan+1);
            value = GetValueCurveInt(name, 0, SettingsMap, eff_pos);
            SetColorBasedOnStringType(value, 2, color, string_type);
            if( num_channels >= base_chan+2 ) {
                name = wxString::Format("DMX%d", base_chan+2);
                value = GetValueCurveInt(name, 0, SettingsMap, eff_pos);
                SetColorBasedOnStringType(value, 3, color, string_type);
            } else {
                return_val = true;
            }
        } else {
            return_val = true;
        }
        buffer.SetPixel(node-1, 0, color);
    } else {
        return_val = true;
    }
    return return_val;
}

void DMXEffect::Render(Effect *effect, const SettingsMap &SettingsMap, RenderBuffer &buffer) {
    double eff_pos = buffer.GetEffectTimeIntervalPosition();
    wxArrayString parts = wxSplit(SettingsMap.Get("CHOICE_Num_Dmx_Channels", "Use 1 Channel"), ' ');
    int num_channels = wxAtoi(parts[1]);

    if (buffer.cur_model == "") {
        return;
    }
    Model* model_info = buffer.frame->AllModels[buffer.cur_model];
    if (model_info == nullptr) {
        return;
    }

    const std::string& string_type = model_info->GetStringType();

    xlColor color = xlBLACK;

    if (string_type.find("Single Color") != std::string::npos) {
        // handle channels for single color nodes
        if( SetDMXSinglColorPixel(1, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(2, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(3, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(4, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(5, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(6, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(7, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(8, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(9, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(10, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(11, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(12, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(13, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(14, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(15, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(16, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(17, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
        if( SetDMXSinglColorPixel(18, num_channels, SettingsMap, eff_pos, color, buffer) ) return;
   } else {
        // handle channels for 3 color nodes
        if( SetDMXRGBNode(1, num_channels, SettingsMap, eff_pos, color, buffer, string_type) ) return;
        if( SetDMXRGBNode(2, num_channels, SettingsMap, eff_pos, color, buffer, string_type) ) return;
        if( SetDMXRGBNode(3, num_channels, SettingsMap, eff_pos, color, buffer, string_type) ) return;
        if( SetDMXRGBNode(4, num_channels, SettingsMap, eff_pos, color, buffer, string_type) ) return;
        if( SetDMXRGBNode(5, num_channels, SettingsMap, eff_pos, color, buffer, string_type) ) return;
        if( SetDMXRGBNode(6, num_channels, SettingsMap, eff_pos, color, buffer, string_type) ) return;
    }

}
