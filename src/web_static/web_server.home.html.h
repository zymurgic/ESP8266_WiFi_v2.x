static const char CONTENT_HOME_HTML[] PROGMEM = 
  "<!doctype html> <html lang=\"en\"> <head> <meta charset=\"utf-8\"> <title>OpenEVSE</title> <meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"> <meta name=\"viewport\" content=\"width=device-width,user-scalable=no\"> <meta name=\"description\" content=\"OpenEVSE\"> <meta name=\"author\" content=\"OpenEVSE\"> <meta name=\"theme-color\" content=\"#000000\"> <link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"> <link rel=\"icon\" type=\"image/png\" href=\"favicon-32x32.png\" sizes=\"32x32\"> <link rel=\"icon\" type=\"image/png\" href=\"favicon-16x16.png\" sizes=\"16x16\"> </head> <body> <div id=\"page\"> <div class=\"header\"> <h1>Open<span>EVSE</span></h1> <h3>WiFi</h3> </div> <div class=\"container\" data-bind=\"visible: !initialised()\"> Loading, please wait... (<span data-bind=\"text: itemsLoaded\"></span>/<span data-bind=\"text: itemsTotal\"></span>) </div> <div class=\"container\" data-bind=\"visible: initialised\" style=\"display: none\"> <div class=\"tabs\"> <input id=\"tab-3\" type=\"radio\" name=\"tab-group\" data-bind=\"checked: tab\" value=\"status\"> <label for=\"tab-3\">OpenEVSE</label> <input id=\"tab-1\" type=\"radio\" name=\"tab-group\" data-bind=\"checked: tab\" value=\"system\"> <label for=\"tab-1\">System</label> <input id=\"tab-2\" type=\"radio\" name=\"tab-group\" data-bind=\"checked: tab\" value=\"services\"> <label for=\"tab-2\">Services</label> <input id=\"tab-4\" type=\"radio\" name=\"tab-group\" data-bind=\"checked: tab\" value=\"rapi\"> <label for=\"tab-4\" data-bind=\"visible: developerMode\">RAPI</label> </div> <div id=\"content\"> <div id=\"content-1\" data-bind=\"visible: isSystem\"> <div class=\"box380 left\"> <h2>WiFi Setup</h2> <p><b>Mode:</b> <span id=\"mode\" data-bind=\"text: status.fullMode\"></span></p> <div id=\"client-view\" data-bind=\"visible: !wifi.canConfigure() &amp;&amp; !wifi.wifiConnecting()\"> <table> <tr> <th>Network</th> <th>RSSI dBm</th> </tr> <tbody id=\"sta-ssid\"> <tr data-bind=\"click: function () { wifi.forceConfig(true); }\"> <td data-bind=\"text: config.ssid\"></td> <td data-bind=\"text: status.srssi\"></td> </tr> </tbody> </table> <button data-bind=\"click: function () { wifi.forceConfig(true); }\">Change WiFi network</button> <p><b>IP Address:</b><br><a data-bind=\"text: status.ipaddress, attr: {href: 'http://'+status.ipaddress()}\"></a></p> <p> <b>Successful packets:</b><br> <span data-bind=\"text: status.packets_success\"></span> of <span data-bind=\"text: status.packets_sent\"></span> </p> <p><b>OpenEVSE</b></p> <p><b>RAPI packets:</b><br><span data-bind=\"text: status.comm_success\"></span> of <span data-bind=\"text: status.comm_sent\"></span></p> <button id=\"apoff\" data-bind=\"visible: status.isWifiAccessPoint, click: wifi.turnOffAccessPoint, disable: wifi.turnOffAccessPointFetching\">Turn off Access Point</button> </div> <div id=\"ap-view\" data-bind=\"visible: wifi.canConfigure() &amp;&amp; !wifi.wifiConnecting()\"> <p>Connect to network:</p> <table> <tr> <th>Select</th> <th>Network</th> <th>RSSI dBm</th> </tr> <tbody id=\"networks\" data-bind=\"foreach: scan.results\"> <tr> <td><input class=\"networkcheckbox\" name=\"network\" data-bind=\"checkedValue: bssid(), checked: $root.wifi.bssid\" type=\"radio\"></td> <td data-bind=\"text: ssid\"></td> <td data-bind=\"text: rssi\"></td> </tr> </tbody> <tfoot data-bind=\"visible: 0 == scan.results().length\"> <tr> <td colspan=\"3\">Scanning...</td> </tr> </tfoot> </table> <p data-bind=\"text: config.ssid\"></p> <p> <b>Passkey:</b><br> <input type=\"text\" autocapitalize=\"none\" autocapitalize=\"none\" data-bind=\"textInput: config.pass\"> <button data-bind=\"click: wifi.saveNetwork, text: (wifi.saveNetworkFetching() ? 'Saving' : (wifi.saveNetworkSuccess() ? 'Saved' : 'Connect')), disable: wifi.saveNetworkFetching\">Connect</button> </p> </div> <div data-bind=\"visible: wifi.wifiConnecting\"> <p>Connecting to WIFI Network...</p> </div> </div> <div class=\"box380 right\"> <h2>Administration</h2> <p> <b>Username:</b><br> <input type=\"text\" autocapitalize=\"none\" data-bind=\"textInput: config.www_username\" pattern=\".{15}\" title=\"The field requires 15 characters\" maxlength=\"15\" required=\"\"> <span class=\"small-text validMessage\">15 characters max</span> </p> <p> <b>Password:</b><br> <input type=\"text\" autocapitalize=\"none\" data-bind=\"textInput: config.www_password\" pattern=\".{15}\" title=\"The field requires 15 characters\" maxlength=\"15\" required=\"\"> <span class=\"small-text validMessage\">15 characters max</span><br> <span class=\"small-text\">Web interface HTTP authentication.</span><br><br> <button data-bind=\"click: saveAdmin, text: (saveAdminFetching() ? 'Saving' : (saveAdminSuccess() ? 'Saved' : 'Save')), disable: saveAdminFetching\">Save</button> </p> </div> <div class=\"box380 right\"> <h2>WiFi Firmware</h2> <span class=\"small-text\">ESP8266</span><br> <p><b>Version: </b><span data-bind=\"text: config.version\"></span></p> <iframe style=\"width:380px; height:50px;\" frameborder=\"0\" scrolling=\"no\" marginheight=\"0\" marginwidth=\"0\" data-bind=\"attr: {src: upgradeUrl}\"> </iframe> <p> <button data-bind=\"click: restart, text: (restartFetching() ? 'Restarting...' : 'Restart'), disable: restartFetching\">Restart</button> <button data-bind=\"click: factoryReset, text: (factoryResetFetching() ? 'Resetting...' : 'Factory Reset'), disable: factoryResetFetching\">Factory Reset</button> </p> </div> <div class=\"box380 left\"> <h2>Developer Mode</h2> <div> <b>Enabled: </b> <label class=\"switch\"> <input type=\"checkbox\" data-bind=\"checked: developerMode\"> <div class=\"slider round\"></div> </label> </div> </div> </div> <div id=\"content-2\" data-bind=\"visible: isServices\"> <div class=\"box380 left\"> <h2>&nbsp; Energy Monitoring <img src=\"data:image/png;base64,R0lGODlhAQABAAD/ACwAAAAAAQABAAACADs=\" data-src=\"emoncms.jpg\" align=\"left\"></h2> <p> <input type=\"checkbox\" id=\"emoncms_enabled\" data-bind=\"checked: config.emoncms_enabled\"> <label for=\"emoncms_enabled\"><b>Enable Emoncms</b></label> </p> <p data-bind=\"visible: config.emoncms_enabled\"> <b>Emoncms Server*:</b><br> <input type=\"text\" autocapitalize=\"none\" data-bind=\"textInput: config.emoncms_server\"><br> <span class=\"small-text\">e.g: <a href=\"http://data.openevse.com/emoncms\">data.openevse.com/emoncms</a>, <a href=\"https://emoncms.org\">emoncms.org</a>, <a href=\"http://emonpi/emoncms\">emonpi/emoncms</a> </span><br> </p> <p data-bind=\"visible: config.emoncms_enabled\"> <b>Emoncms Node*:</b><br> <input type=\"text\" autocapitalize=\"none\" data-bind=\"textInput: config.emoncms_node\"> </p> <p data-bind=\"visible: config.emoncms_enabled\"> <b>Emoncms write-apikey*:</b><br> <input type=\"password\" autocapitalize=\"none\" data-bind=\"textInput: config.emoncms_apikey\"><br> </p> <p data-bind=\"visible: config.emoncms_enabled\"> <b>Emoncms SSL SHA-1 Fingerprint (optional):</b><br> <input type=\"text\" autocapitalize=\"none\" data-bind=\"textInput: config.emoncms_fingerprint\"><br> <br><span class=\"small-text\">HTTPS will be enabled if present e.g:</span> <span class=\"small-text\"> 7D:82:15:BE:D7:BC:72:58:87:7D:8E:40:D4:80:BA:1A:9F:8B:8D:DA </span> </p> <p> <button data-bind=\"click: saveEmonCms, text: (saveEmonCmsFetching() ? 'Saving' : (saveEmonCmsSuccess() ? 'Saved' : 'Save')), disable: saveEmonCmsFetching\">Save</button> <span data-bind=\"visible: config.emoncms_enabled\"><b>&nbsp; Connected:&nbsp;<span data-bind=\"text: 1 === status.emoncms_connected() ? 'Yes' : 'No'\"></span></b></span> <span data-bind=\"visible: config.emoncms_enabled() &amp;&amp; 1 === status.emoncms_connected()\"><b>&nbsp; Successful posts:&nbsp;<span data-bind=\"text: status.packets_success\"></span></b></span> </p> </div> <div class=\"box380 right\"> <h2>MQTT</h2> <p> <input type=\"checkbox\" id=\"mqtt_enabled\" data-bind=\"checked: config.mqtt_enabled\"> <label for=\"mqtt_enabled\"><b>Enable MQTT</b></label> <span class=\"info\" data-bind=\"click: toggle.bind($data, showMqttInfo)\"></span> </p> <div class=\"box\" data-bind=\"visible: showMqttInfo\"> <div> Status published to:<br> <span class=\"small-text\">{base-topic}/{status} value</span><br> <span class=\"small-text\">e.g. <span data-bind=\"text: '' !== config.mqtt_topic() ? config.mqtt_topic() : 'openevse'\"></span>/amp 16</span><br> </div> <p> RAPI control subscribes to:<br> <span class=\"small-text\">{base-topic}/rapi/in/{command} value</span><br> <span class=\"small-text\">e.g. <span data-bind=\"text: '' !== config.mqtt_topic() ? config.mqtt_topic() : 'openevse'\"></span>/rapi/in/$SC 16</span><br> <span class=\"small-text\">e.g. <span data-bind=\"text: '' !== config.mqtt_topic() ? config.mqtt_topic() : 'openevse'\"></span>/rapi/in/$GC</span><br> </p> <p> RAPI response published to:<br> <span class=\"small-text\">{base-topic}/rapi/out response</span><br> <span class=\"small-text\">e.g. <span data-bind=\"text: '' !== config.mqtt_topic() ? config.mqtt_topic() : 'openevse'\"></span>/rapi/out $OK 6 32</span><br> </p> </div> <p data-bind=\"visible: config.mqtt_enabled\"> <b>Host*:</b><br> <input data-bind=\"textInput: config.mqtt_server\" type=\"text\" autocapitalize=\"none\"><br> <span class=\"small-text\">e.g 'emonpi', 'test.mosquitto.org', '192.168.1.4'</span> </p> <p data-bind=\"visible: config.mqtt_enabled\"> <b>Username:</b><span> blank - no authentication</span> <input data-bind=\"textInput: config.mqtt_user\" type=\"text\" autocapitalize=\"none\"> </p> <p data-bind=\"visible: config.mqtt_enabled\"> <b>Password:</b><span> blank - no authentication</span> <input data-bind=\"textInput: config.mqtt_pass\" type=\"password\" autocapitalize=\"none\"><br> </p> <p data-bind=\"visible: config.mqtt_enabled\"> <b>Base-topic*:</b><br> <input data-bind=\"textInput: config.mqtt_topic\" type=\"text\" autocapitalize=\"none\"><br> <span class=\"small-text\">e.g 'openevse'</span> </p> <h2 data-bind=\"visible: config.mqtt_enabled\">Solar PV divert<span class=\"info\" data-bind=\"click: toggle.bind($data, showSolarDivert)\"></span></h2> <div class=\"box\" data-bind=\"visible: showSolarDivert() &amp;&amp; config.mqtt_enabled()\"> <div>Dynamically adjust charge rate based on solar PV generation or excess power (grid export).</div> <p> <b>1. Normal (default):</b> </p><ul> <li><span class=\"small-text\">Charge at maximum current set by EVSE.</span></li> </ul> <b>2. Eco:</b> <ul> <li><span class=\"small-text\">If only solar PV feed available: charge rate is modulated based on <b>solar PV generation.</b></span></li> <li><span class=\"small-text\">If grid +I/-E (positive Import / negative Export) feed is available: charge rate will be modulated by available <b>excess power.</b></span></li> <li><span class=\"small-text\">If EVSE is sleeping: charging will begin when solar PV / excess power > min charge rate.</span></li> <li><span class=\"small-text\">Charging will not pause; this avoids excess wear on the EVSE relay and the EV.</span></li> </ul> <span class=\"small-text\"><i>Note: It's assumed that EVSE power is included in the grid feed.</i></span><br> <p></p> </div> <p data-bind=\"visible: config.mqtt_enabled\"> <b>SolarPV-gen topic:</b> <input data-bind=\"textInput: config.mqtt_solar, enable: '' === config.mqtt_grid_ie()\" type=\"text\" autocapitalize=\"none\" hint=\"emon/emonpi/power2\"><br> <span class=\"small-text\">Solar PV MQTT topic to modulate charge rate based on solar </span></p> <p data-bind=\"visible: config.mqtt_enabled\"> <b>Grid (+I/-E) topic:</b><br> <input data-bind=\"textInput: config.mqtt_grid_ie, enable: '' === config.mqtt_solar()\" type=\"text\" autocapitalize=\"none\" hint=\"emon/emonpi/power1\"><br> <span class=\"small-text\">Grid (+I/-E) MQTT topic to modulate charge rate based on <b>excess power</b></span> </p> <button data-bind=\"click: saveMqtt, text: (saveMqttFetching() ? 'Saving' : (saveMqttSuccess() ? 'Saved' : 'Save')), disable: saveMqttFetching\">Save</button> <span data-bind=\"visible: config.mqtt_enabled\"><b>&nbsp; Connected:&nbsp;<span data-bind=\"text: 1 === status.mqtt_connected() ? 'Yes' : 'No'\"></span></b></span> <p></p> </div> <div class=\"box380 left\"> <h2>&nbsp; OhmConnect <img src=\"data:image/png;base64,R0lGODlhAQABAAD/ACwAAAAAAQABAAACADs=\" data-src=\"ohm.jpg\" align=\"left\"></h2> <p> <input type=\"checkbox\" id=\"ohm_enabled\" data-bind=\"checked: config.ohm_enabled\"> <label for=\"ohm_enabled\"><b>Enable OhmConnect</b></label> <a href=\"https://ohm.co/openevse\" rel=\"nofollow\">Click Here to Join</a> </p> <p data-bind=\"visible: config.ohm_enabled\"> OhmConnect monitors real-time conditions on the electricity grid. When dirty and unsustainable power plants turn on, our users receive a notification to save energy. </p> <p data-bind=\"visible: config.ohm_enabled\"> <b>Ohm Hour:</b> <span data-bind=\"text: status.ohm_hour\"></span> </p> <p data-bind=\"visible: config.ohm_enabled\"> <b>Ohm key:</b><br> <input data-bind=\"textInput: config.ohmkey\" type=\"text\" autocapitalize=\"none\"> </p> <p data-bind=\"visible: config.ohm_enabled\"> <strong>USA - California only</strong> </p> <div style=\"padding:56.25% 0 0 0;position:relative;\"><iframe src=\"https://player.vimeo.com/video/119419875\" style=\"position:absolute;top:0;left:0;width:100%;height:100%;\" frameborder=\"0\" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe></div><script src=\"https://player.vimeo.com/api/player.js\"></script> <p data-bind=\"visible: config.ohm_enabled\"> Ohm Key can be obtained by logging in to OhmConnect, enter Settings and locate the link in \"Open Source Projects\"<br> Example: https://login.ohmconnect.com/verify-ohm-hour/OpnEoVse<br> <b>Key: </b>OpnEoVse </p> <p> <button data-bind=\"click: saveOhmKey, text: (saveOhmKeyFetching() ? 'Saving' : (saveOhmKeySuccess() ? 'Saved' : 'Save')), disable: saveOhmKeyFetching\">Save</button> </p> </div> </div> <div id=\"content-3\" data-bind=\"visible: isStatus\"> <div data-bind=\"visible: openevse.isError\" class=\"box box-full left error\"> <h4>EVSE Error</h4> <span data-bind=\"text: status.estate\"></span> </div> <div data-bind=\"visible: !openevse.isError(),\n"
  "                          css: { ready: openevse.isReady(),\n"
  "                                 connected: openevse.isConnected() &amp;&amp; !openevse.isCharging(),\n"
  "                                 charging: openevse.isCharging(),\n"
  "                                 sleeping: openevse.isSleeping() }\" class=\"box box-full left\"> <h2 class=\"left\">Session Status</h2> <h2 class=\"right\" data-bind=\"text: status.estate\"></h2> <table> <tr> <th>Current</th> <th>Energy</th> <th>Temp</th> <th>Elapsed</th> </tr> <tr> <td><span data-bind=\"text: scaleString(status.amp(), 1000, 2) + ' A'\"></span></td> <td><span data-bind=\"text: scaleString(status.wattsec(), 3600000, 2) + ' kWh'\"></span></td> <td><span data-bind=\"text: scaleString(status.temp1(), 10, 1) + ' &deg;C'\"></span></td> <td><span data-bind=\"text: openevse.time.elapsed\"></span></td> </tr> </table> </div> <div class=\"box380 left\"> <h2>Charge Options</h2> <p data-bind=\"with: openevse, visible: !openevse.isError()\"> <button data-bind=\"click: setStatus.bind($data, 'enable'), visible: !isEnabled()\">Start</button> <button data-bind=\"click: setStatus.bind($data, 'sleep'), visible: !isSleeping()\">Pause</button> </p> <hr> <p data-bind=\"with: openevse\"> <b>Time limit:</b><br> <select data-bind=\"options: timeLimits,\n"
  "                                 optionsText: 'name',\n"
  "                                 optionsValue: 'value',\n"
  "                                 value: timeLimit,\n"
  "                                 enable: !updatingTimeLimit() &amp;&amp; isConnected(),\n"
  "                                 css: { saved: savedTimeLimit }\"></select> </p> <p data-bind=\"with: openevse\"> <b>Energy limit:</b><br> <select type=\"text\" data-bind=\"options: chargeLimits,\n"
  "                                             optionsText: 'name',\n"
  "                                             optionsValue: 'value',\n"
  "                                             value: chargeLimit,\n"
  "                                             enable: !updatingChargeLimit() &amp;&amp; isConnected(),\n"
  "                                             css: { saved: savedChargeLimit }\"></select> </p> <hr> <br> <div data-bind=\"with: openevse\"> <b>Timer:</b><br> Start: <input type=\"time\" data-bind=\"value: delayTimerStart, disable: isError\"> &nbsp;&nbsp; Stop: <input type=\"time\" data-bind=\"value: delayTimerStop, disable: isError\"><br> <br> <button data-bind=\"text: delayTimerEnabled() ? 'Update' : 'Set',\n"
  "                                   enable: !updatingDelayTimer() &amp;&amp;\n"
  "                                           delayTimerValid() &amp;&amp;\n"
  "                                           !isError(),\n"
  "                                   click: startDelayTimer\">Set</button> <button data-bind=\"visible: delayTimerEnabled(),\n"
  "                                   enable: !updatingDelayTimer() &amp;&amp;\n"
  "                                           !isError(),\n"
  "                                   click: stopDelayTimer\">Cancel</button> </div> </div> <div class=\"box380 right\" data-bind=\"visible: advancedMode\"> <h2>Energy</h2> <table> <tr> <th>Energy</th> <th></th> </tr> <tr> <td>This Session:</td> <td><span data-bind=\"text: scaleString(status.wattsec(), 3600000, 2)+ ' kWh'\"></span></td> </tr> <tr> <td>Total:</td> <td><span data-bind=\"text: scaleString(status.watthour(), 1000, 2)+ ' kWh'\"></span></td> </tr> </table> </div> <div class=\"box380 right\"> <h2>Charge Mode <span class=\"info\" data-bind=\"click: toggle.bind($data, showSolarDivert)\"></span></h2> <div class=\"box error\" data-bind=\"visible: !isEcoModeAvailable()\"> <h4>MQTT config not configured with Solar PV / Grid topic.</h4> Solar PV Divert requires the SolarPV-gen or Grid (+I/-E) MQTT topic to be defined on the <a href=\"#services\" data-bind=\"click: function() { tab('services'); config.mqtt_enabled(true); }\">Services</a> tab. </div> <div class=\"box\" data-bind=\"visible: showSolarDivert()\"> <div>Dynamically adjust charge rate based on solar PV generation or excess power (grid export).</div> <p> <b>1. Normal (default):</b> </p><ul> <li><span class=\"small-text\">Charge at maximum current set by EVSE.</span></li> </ul> <b>2. Eco (solar PV divert):</b> <ul> <li><span class=\"small-text\">If only solar PV feed available: charge rate is modulated based on <b>solar PV generation.</b></span></li> <li><span class=\"small-text\">If grid +I/-E (positive Import / negative Export) feed is available: charge rate will be modulated by available <b>excess power.</b></span></li> <li><span class=\"small-text\">If EVSE is sleeping: charging will begin when solar PV / excess power > min charge rate.</span></li> <li><span class=\"small-text\">Charging will not pause; this avoids excess wear on the EVSE relay and the EV.</span></li> </ul> <span class=\"small-text\"><i>Note: It's assumed that EVSE power is included in the grid feed</i></span><br><br> <span class=\"small-text\"><i>Charging mode can also be set via MQTT:<br>{base-topic}/divertmode/set</i></span> <p></p> </div> <div data-bind=\"visible: isEcoModeAvailable\"> <span data-bind=\"css: {selected: !ecoMode() }\">Normal (max)</span> <label class=\"switch\"> <input type=\"checkbox\" data-bind=\"checked: ecoMode\"> <div class=\"slider round\"></div> </label> <span data-bind=\"css: {selected: ecoMode }\">Eco (PV divert)</span><br> </div> <div data-bind=\"visible: isEcoModeAvailable\"> <br> <span data-bind=\"visible: haveSolar\"><b>Solar:</b></span> <span data-bind=\"visible: haveGridIe\"><b>Grid Import/Export:</b></span> <span data-bind=\"text: haveGridIe() ? status.grid_ie() : status.solar()\"></span>W - <span data-bind=\"text: formatUpdate(openevse.time.divert_update()), css: updateClass(openevse.time.divert_update())\"></span> <span data-bind=\"visible: ecoMode\"> | <b>Charge rate:</b> <span data-bind=\"text: status.charge_rate\"></span>A</span> </div> </div> <div class=\"box380 right\" data-bind=\"visible: advancedMode\"> <h2>Sensor Values</h2> <table> <tr> <th>Sensor</th> <th>Value</th> </tr> <tr> <td>Pilot:</td> <td><span data-bind=\"text: status.pilot() + ' A'\"></span></td> </tr> <tr> <td>Current Now:</td> <td><span data-bind=\"text: scaleString(status.amp(), 1000, 2) + ' A'\"></span></td> </tr> <tr> <td>Temp1:</td> <td><span data-bind=\"text: scaleString(status.temp1(), 10, 1) + ' &deg;C'\"></span></td> </tr> <tr> <td>Temp2:</td> <td><span data-bind=\"text: scaleString(status.temp2(), 10, 1) + ' &deg;C'\"></span></td> </tr> <tr> <td>Temp3:</td> <td><span data-bind=\"text: scaleString(status.temp3(), 10, 1) + ' &deg;C'\"></span></td> </tr> </table> </div> <div class=\"box380 setup\" data-bind=\"with: openevse, css: { right: !advancedMode(), left: advancedMode() }\"> <h2>Setup</h2> <p data-bind=\"with: time, visible: !time.hasRTC()\"> <b>Time: No RTC detected</b> </p> <p data-bind=\"with: time, visible: time.hasRTC()\"> <b>Time:</b><br> <input type=\"date\" data-bind=\"value: date, disable: automaticTime\"> <input type=\"time\" data-bind=\"value: time, disable: automaticTime\"><br> </p> <div data-bind=\"with: time, visible: time.hasRTC()\"> <span data-bind=\"css: {selected: !automaticTime() }\">Manual</span> <label class=\"switch\"> <input type=\"checkbox\" data-bind=\"checked: automaticTime\"> <div class=\"slider round\"></div> </label> <span data-bind=\"css: {selected: automaticTime() }\">Automatic<span> <button style=\"margin-left: 30px\" data-bind=\"click: setTime\">Sync</button> </span></span></div> <hr> <p> <b>Service Level:</b><br> <select data-bind=\"options: serviceLevels,\n"
  "                                 optionsText: 'name',\n"
  "                                 optionsValue: 'value',\n"
  "                                 value: serviceLevel,\n"
  "                                 disable: updatingServiceLevel(),\n"
  "                                 css: { saved: savedServiceLevel }\"></select> </p> <p> <b>Max Current:</b><br> <select data-bind=\"options: currentLevels,\n"
  "                                  optionsText: 'name',\n"
  "                                  optionsValue: 'value',\n"
  "                                  value: currentCapacity,\n"
  "                                  disable: updatingServiceLevel() || updatingCurrentCapacity(),\n"
  "                                  css: { saved: savedCurrentCapacity }\"></select> </p> </div> <div class=\"box380 right\" data-bind=\"visible: advancedMode\"> <h2>Current</h2> <table> <tr> <th>Name</th> <th> </th> </tr> <tr> <td>Service Level:</td> <td> <span data-bind=\"text: openevse.actualServiceLevel\"></span> </td> </tr> <tr> <td>Level <span data-bind=\"text: openevse.actualServiceLevel\"></span> Minimum:</td> <td> <span data-bind=\"text: openevse.minCurrentLevel() + ' A'\"></span> </td> </tr> <tr> <td>Level <span data-bind=\"text: openevse.actualServiceLevel\"></span> Maximum:</td> <td> <span data-bind=\"text: openevse.maxCurrentLevel() + ' A'\"></span> </td> </tr> <tr> <td>Sensor Scale:</td> <td><span data-bind=\"text: config.scale\"></span></td> </tr> <tr> <td>Sensor Offset:</td> <td><span data-bind=\"text: config.offset\"></span></td> </tr> </table> </div> <div class=\"box380 left\" data-bind=\"visible: advancedMode() || !openevse.allTestsEnabled()\"> <h2>Safety<span class=\"info\" data-bind=\"click: toggle.bind($data, showSafety)\"></span></h2> <div class=\"box\" data-bind=\"visible: showSafety()\"> Hardware safety checks. Enable dev mode (System > Developer Mode) to enable/disable or use the physical LCD + menu button. </div> <div data-bind=\"visible: !openevse.allTestsEnabled()\" class=\"box warning\"> <h4>Warning!!</h4> Not all the safety tests are enabled, please take extra care before charging your vehicle. </div> <table> <tr> <th>Test</th> <th>Status</th> </tr> <tr data-bind=\"css: {error: 9 === status.state() }\"> <td>GFI Self Test:</td> <td> <label class=\"switch\" data-bind=\"visible: developerMode\"> <input type=\"checkbox\" data-bind=\"checked: openevse.gfiSelfTestEnabled\"> <div class=\"slider round\"></div> </label> <span data-bind=\"text: openevse.gfiSelfTestEnabled() ? 'Enabled' : 'Disabled'\"></span> </td> </tr> <tr data-bind=\"css: {error: 7 === status.state() }\"> <td>Ground Monitoring:</td> <td> <label class=\"switch\" data-bind=\"visible: developerMode\"> <input type=\"checkbox\" data-bind=\"checked: openevse.groundCheckEnabled\"> <div class=\"slider round\"></div> </label> <span data-bind=\"text: openevse.groundCheckEnabled() ? 'Enabled' : 'Disabled'\"></span> </td> </tr> <tr data-bind=\"css: {error: 8 === status.state() }\"> <td>Stuck Contact Detection:</td> <td> <label class=\"switch\" data-bind=\"visible: developerMode\"> <input type=\"checkbox\" data-bind=\"checked: openevse.stuckRelayEnabled\"> <div class=\"slider round\"></div> </label> <span data-bind=\"text: openevse.stuckRelayEnabled() ? 'Enabled' : 'Disabled'\"></span> </td> </tr> <tr data-bind=\"css: {error: 10 === status.state() }\"> <td>Temperature Monitoring:</td> <td> <label class=\"switch\" data-bind=\"visible: developerMode() &amp;&amp; openevse.tempCheckSupported()\"> <input type=\"checkbox\" data-bind=\"checked: openevse.tempCheckEnabled\"> <div class=\"slider round\"></div> </label> <span data-bind=\"text: openevse.tempCheckEnabled() ? 'Enabled' : 'Disabled'\"></span> </td> </tr> <tr data-bind=\"css: {error: 5 === status.state() }\"> <td>Diode Check:</td> <td> <label class=\"switch\" data-bind=\"visible: developerMode\"> <input type=\"checkbox\" data-bind=\"checked: openevse.diodeCheckEnabled\"> <div class=\"slider round\"></div> </label> <span data-bind=\"text: openevse.diodeCheckEnabled() ? 'Enabled' : 'Disabled'\"></span> </td> </tr> <tr data-bind=\"css: {error: 4 === status.state() }\"> <td>Vent Required:</td> <td> <label class=\"switch\" data-bind=\"visible: developerMode\"> <input type=\"checkbox\" data-bind=\"checked: openevse.ventRequiredEnabled\"> <div class=\"slider round\"></div> </label> <span data-bind=\"text: openevse.ventRequiredEnabled() ? 'Enabled' : 'Disabled'\"></span> </td> </tr> <tr> <th>Error</th> <th>Count</th> </tr> <tr> <td>GFCI:</td> <td><span data-bind=\"text: status.gfcicount\"></span></td> </tr> <tr> <td>No Ground:</td> <td><span data-bind=\"text: status.nogndcount\"></span></td> </tr> <tr> <td>Stuck Contact:</td> <td><span data-bind=\"text: status.stuckcount\"></span></td> </tr> </table> </div> <div class=\"box380 right\" data-bind=\"visible: advancedMode\"> <h2>Hardware</h2> <table> <tr> <th>OpenEVSE</th> <th></th> </tr> <tr> <td>Firmware:</td> <td><span data-bind=\"text: config.firmware\"></span></td> </tr> <tr> <td>Protocol:</td> <td><span data-bind=\"text: config.protocol\"></span></td> </tr> <tr> <td colspan=\"2\" data-bind=\"with: openevse\"> <button data-bind=\"click: restart, text: (restartFetching() ? 'Restarting...' : 'Restart'), disable: restartFetching\">Restart</button> </td> </tr> <tr> <th>OpenEVSE WiFi</th> <th></th> </tr> <tr> <td>Firmware:</td> <td><span data-bind=\"text: config.version\"></span></td> </tr> <tr> <td>Flash Size:</td> <td><span data-bind=\"text: scaleString(config.espflash(), 1024, 0) + 'K'\"></span></td> </tr> <tr> <td>Free RAM:</td> <td><span data-bind=\"text: scaleString(status.free_heap(), 1024, 0) + 'K'\"></span></td> </tr> <tr> <td colspan=\"2\"> <button data-bind=\"click: restart, text: (restartFetching() ? 'Restarting...' : 'Restart'), disable: restartFetching\">Restart</button> </td> </tr> </table> </div> <div class=\"box380\" data-bind=\"css: { right: !advancedMode() &amp;&amp; !openevse.allTestsEnabled(),\n"
  "                                                left: advancedMode() || openevse.allTestsEnabled() }\"> <h2>Display</h2> <div> <span data-bind=\"css: {selected: !advancedMode() }\">Simple</span> <label class=\"switch\"> <input type=\"checkbox\" data-bind=\"checked: advancedMode\"> <div class=\"slider round\"></div> </label> <span data-bind=\"css: {selected: advancedMode }\">Advanced</span><br> </div> </div> </div> <div id=\"content-4\" data-bind=\"visible: isRapi\"> <div class=\"box380 left\"> <form method=\"get\" action=\"r\" data-bind=\"with: rapi\"> <p> <b>RAPI Command:</b> <input type=\"text\" autocapitalize=\"none\" name=\"rapi\" length=\"32\" data-bind=\"textInput: cmd\"> </p> <p> <button data-bind=\"click: send, disable: rapiSend\">Send</button> </p> <p data-bind=\"text: ret\"></p> </form> </div> <div class=\"box380 right\"> <h2>RAPI System Functions</h2> <table> <tr> <th>Function</th> <th>Description</th> </tr> <tr> <td>$FB</td> <td>LCD Backlight Color (0-7)</td> </tr> <tr> <td>$FD</td> <td>Disable EVSE</td> </tr> <tr> <td>$FE</td> <td>Enable EVSE</td> </tr> <tr> <td>$FP</td> <td>Output text at x y position text to LCD (x y text)</td> </tr> <tr> <td>$FR</td> <td>Reset EVSE</td> </tr> <tr> <td>$FS</td> <td>Put EVSE to sleep</td> </tr> </table> </div> <div class=\"box380 left\"> <h2>RAPI Get Commands</h2> <table> <tr> <th>Get</th> <th>Description</th> </tr> <tr> <td>$G3</td> <td>Get Charge Time Limit, 15-minutes (1), 30-minutes (2), etc...</td> </tr> <tr> <td>$GA</td> <td>Get Ammeter Scale/Offset, scale offset</td> </tr> <tr> <td>$GC</td> <td>Get current capacity range, integers</td> </tr> <tr> <td>$GE</td> <td>Get settings, amps flags</td> </tr> <tr> <td>$GF</td> <td>Get fault counters, gfi ground stuck (in hex)</td> </tr> <tr> <td>$GG</td> <td>Get charge current and voltage, milliamps millivolts</td> </tr> <tr> <td>$GH</td> <td>Get charge limit in kWh, integer</td> </tr> <tr> <td>$GM</td> <td>Get Voltmeter Scale/Offset, scale offset</td> </tr> <tr> <td>$GO</td> <td>Get Overtemperature thresholds, ambient infrared</td> </tr> <tr> <td>$GP</td> <td>Get Temperatures, LCD mcp9808 infrared (all integers, Celsius * 10)</td> </tr> <tr> <td>$GS</td> <td>Get EVSE State, state elapsed_seconds</td> </tr> <tr> <td>$GT</td> <td>Get time, year month day hour minute second</td> </tr> <tr> <td>$GU</td> <td>Get Energy usage, wattseconds watt_hour_accumulated</td> </tr> <tr> <td>$GV</td> <td>Get Versions, evse_firmware protocol_version</td> </tr> </table> </div> <div class=\"box380 right\"> <h2>RAPI Set Commands</h2> <table> <tr> <th>Set</th> <th>Description</th> </tr> <tr> <td>$S0</td> <td>Set LCD Type, Monochrome (0), Color (1)</td> </tr> <tr> <td>$S1</td> <td>Set RTC Year Month Day Hour Minute Second (all 2-digit max)</td> </tr> <tr> <td>$S2</td> <td>Enable (1)/ Disable (0) Ammeter Calibration Mode</td> </tr> <tr> <td>$S3</td> <td>Set Charge Time Limit, 15-minutes (1), 30-minutes (2), etc...</td> </tr> <tr> <td>$SA</td> <td>Set Ammeter Scale/Offset, scale offset</td> </tr> <tr> <td>$SC</td> <td>Set current capacity, integer</td> </tr> <tr><td>$SD</td><td>Enable (1) / Disable (0) Diode self-check</td></tr> <tr> <td>$SF</td> <td>Enable (1) / Disable (0) GFI self-check</td> </tr> <tr> <td>$SG</td> <td>Enable (1) / Disable (0) Ground check</td> </tr> <tr> <td>$SH</td> <td>Set charge limit in kWh, integer</td> </tr> <tr> <td>$SK</td> <td>Set accumulated Wh, integer</td> </tr> <tr><td>$SL</td><td>Set service level (1/2/A)</td></tr> <tr> <td>$SM</td> <td>Set Voltmeter Scale/Offset, scale offset</td> </tr> <tr> <td>$SO</td> <td>Set Overtemperature thresholds, ambient infrared</td> </tr> <tr> <td>$SR</td> <td>Enable (1) / Disable (0) Stuck-relay check</td> </tr> <tr> <td>$SS</td> <td>Enable (1) / Disable (0) GFI self-check</td> </tr> <tr> <td>$ST</td> <td>Set timer, start_hour start_min end_hour end_min</td> </tr> <tr> <td>$SV</td> <td>Enable (1) / Disable (0) vent required check</td> </tr> </table> </div> </div> </div> <div id=\"footer\"> <br><b> Powered by <a href=\"http://www.openevse.com\">OpenEVSE</a> and <a href=\"https://openenergymonitor.org\">OpenEnergyMonitor</a></b> <br> <b>Version: </b>V<span data-bind=\"text: config.version\"></span> </div> </div> </div> <script src=\"lib.js\"></script> <script src=\"home.js\"></script> </body> </html> \n";
