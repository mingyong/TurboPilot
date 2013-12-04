__author__ = 'WLH'
# -*- coding: UTF-8 –*-

from temputils import  *
from uavobj import *
from moduleinfo import *

from xml.dom import minidom
import codecs

import sys
# Python2.5 初始化后会删除 sys.setdefaultencoding 这个方法，我们需要重新载入
reload(sys)
sys.setdefaultencoding('utf-8')

#Open Template files
txt = codecs.open('./template/tmp_uobj.h', 'r').read()
temp_uobj_inc = UavTemplate(txt)
txt = codecs.open('./template/tmp_uobj.c', 'r').read()
temp_uobj_src = UavTemplate(txt)

txt = codecs.open('./template/tmp_uobjadmin.h', 'r').read()
temp_uobjadmin_inc = UavTemplate(txt)
txt = codecs.open('./template/tmp_uobjadmin.c', 'r').read()
temp_uobjadmin_src = UavTemplate(txt)

txt = codecs.open('./template/tmp_module.h', 'r').read()
temp_module_inc = UavTemplate(txt)
txt = codecs.open('./template/tmp_module.c', 'r').read()
temp_module_src = UavTemplate(txt)

txt = codecs.open('./template/tmp_statuscode.h', 'r').read()
temp_statuscode_inc = UavTemplate(txt)

#Open XML data type define files
doc_uavobj  = minidom.parse("./share/objdefine.xml")
doc_modules = minidom.parse("./share/modules.xml")
doc_statuscode = minidom.parse("./share/statuscode.xml")

#Proc xml info in loop
uavobjList = []
uobjItems = doc_uavobj.getElementsByTagName("UavObj")
for i, uobjitem in enumerate(uobjItems):
    uobj = UavObject()
    uobj.Name = uobjitem.getAttribute("Name")
    uobj.Desc = uobjitem.getElementsByTagName("Desc")[0].firstChild.data
    uobj.GcsAccess = uobjitem.getElementsByTagName("Access")[0].getAttribute("gcs")
    uobj.FlightAccess = uobjitem.getElementsByTagName("Access")[0].getAttribute("flight")
    uobj.InstCnt = int(uobjitem.getAttribute("InstCnt"))
    uobj.TypeID = i
    
    # 解析成员变量
    memItesms = uobjitem.getElementsByTagName("Member")
    for j, memItem in enumerate(memItesms):
        memInfo = MemberInfo()
        memInfo.Name = memItem.getAttribute("name")
        memInfo.Type = memItem.getAttribute("type")
        memInfo.Unit = memItem.getAttribute("units")
        memInfo.Elements = memItem.getAttribute("Elements")        
        if("" == memInfo.Elements):
            memInfo.Elements = "1"
        memInfo.Note = memItem.getAttribute("note")
        uobj.MemberList.append(memInfo)
    uavobjList.append(uobj)

# 至此已将XML描述转换成Python中对象
# Debug
#for item in uavobjList:
#    item.Dump()

############################################################
# uobjadmin 模板处理开始
dict_uobjadmin_inc = dict()
dict_uobjadmin_inc["UOBJ_TYPE_CNT"] = str(len(uavobjList))
outfile = codecs.open('../uavobj/uobjadmin.h', 'w')
txt = temp_uobjadmin_inc.safe_substitute(dict_uobjadmin_inc)
outfile.write(txt)
outfile.close()

dict_uobjadmin_src = dict()
dict_uobjadmin_src["UOBJ_TYPE_CNT"] = str(len(uavobjList))
dict_uobjadmin_src["UOBJ_INC"]      = ""
dict_uobjadmin_src["ALL_UOBJ_INIT"] = ""
for objitem in uavobjList:
    dict_uobjadmin_src["UOBJ_INC"] += '#include "uobj_%s.h"\n' % objitem.Name.lower()
    dict_uobjadmin_src["ALL_UOBJ_INIT"] += '\t%s_Init();\n' % objitem.Name

outfile = codecs.open('../uavobj/uobjadmin.c', 'w')
txt = temp_uobjadmin_src.safe_substitute(dict_uobjadmin_src)
outfile.write(txt)
outfile.close()

# uobjadmin 模板处理结束
############################################################

############################################################
# uavdefine 模板处理开始
dict_uobj_inc = dict()
dict_uobj_src = dict()
for i, objitem in enumerate(uavobjList):
    dict_uobj_inc["NAME"] = objitem.Name
    dict_uobj_inc["NAMEUC"] = objitem.Name.upper()
    dict_uobj_inc["TYPEID"] = (i+1)
    dict_uobj_inc["INSTCNT"] = (objitem.InstCnt)
    dict_uobj_inc["MEMBERCNT"] = len(objitem.MemberList)
    # 处理成员变量定义
    dict_uobj_inc["MEMBERS_DEF"] = ""
    for memItem in objitem.MemberList:
        dict_uobj_inc["MEMBERS_DEF"] += ('    %s %s;'%(memItem.Type, memItem.Name)).ljust(30)
        dict_uobj_inc["MEMBERS_DEF"] += '/*!< %s, Units: %s*/\n' % (memItem.Note, memItem.Unit)

    dict_uobj_inc["VALUE_GETTER_DEC"] = ""
    dict_uobj_inc["VALUE_SETTER_DEC"] = ""

    strTemp11 = "extern TP_STATUS %s_GetVal(U32 instId, UObj_%s *valPtr);\n"
    strTemp12 = "extern TP_STATUS %s_SetVal(U32 instId, UObj_%s *valPtr);\n"
    strTemp21 = "extern TP_STATUS %s_GetVal(UObj_%s *valPtr);\n"
    strTemp22 = "extern TP_STATUS %s_SetVal(UObj_%s *valPtr);\n"
    if(objitem.InstCnt > 1):
        dict_uobj_inc["VALUE_GETTER_DEC"] += strTemp11 % (objitem.Name, objitem.Name)
        dict_uobj_inc["VALUE_SETTER_DEC"] += strTemp12 % (objitem.Name, objitem.Name)
    else:
        dict_uobj_inc["VALUE_GETTER_DEC"] += strTemp21 % (objitem.Name, objitem.Name)
        dict_uobj_inc["VALUE_SETTER_DEC"] += strTemp22 % (objitem.Name, objitem.Name)

    dict_uobj_inc["MEM_GETTER_DEC"] = ""
    dict_uobj_inc["MEM_SETTER_DEC"] = ""
    strTemp11 = "extern TP_STATUS %s_Get_%s(U32 instId, %s *valPtr);\n"
    strTemp12 = "extern TP_STATUS %s_Set_%s(U32 instId, %s *valPtr);\n"
    strTemp21 = "extern TP_STATUS %s_Get_%s(%s *valPtr);\n"
    strTemp22 = "extern TP_STATUS %s_Set_%s(%s *valPtr);\n"

    for memItem in objitem.MemberList:
        if(objitem.InstCnt > 1):
            dict_uobj_inc["MEM_GETTER_DEC"] += strTemp11 %(objitem.Name, memItem.Name, memItem.Type)
            dict_uobj_inc["MEM_SETTER_DEC"] += strTemp12 %(objitem.Name, memItem.Name, memItem.Type)
        else:
            dict_uobj_inc["MEM_GETTER_DEC"] += strTemp21 %(objitem.Name, memItem.Name, memItem.Type)
            dict_uobj_inc["MEM_SETTER_DEC"] += strTemp22 %(objitem.Name, memItem.Name, memItem.Type)

    # Uav Object 头文件生成处理
    outfile = codecs.open('../uavobj/uobj_%s.h'%objitem.Name.lower(), 'w')
    txt = temp_uobj_inc.safe_substitute(dict_uobj_inc)
    outfile.write(txt)
    outfile.close()

    dict_uobj_src["NAME"] = objitem.Name
    dict_uobj_src["NAMEUC"] = objitem.Name.upper()
    dict_uobj_src["NAMELC"] = objitem.Name.lower()

    if(objitem.InstCnt == 1):
        dict_uobj_src["INST_DEFINE"] = "static UObj_%s g%sInst;" %(objitem.Name, objitem.Name)
    else:
        dict_uobj_src["INST_DEFINE"] = "static UObj_%s g%sInst[%s];" %(objitem.Name, objitem.Name, objitem.InstCnt)

    dict_uobj_src["MEMSIZEINFO"] = ""
    dict_uobj_src["MEMVAL_SET_INFO"] = ""
    dict_uobj_src["MEMVAL_GET_INFO"] = ""
    strTemp11 = "case %s: memcpy(valPtr, &g%sInst.%s, sizeof(%s));\n\t"
    strTemp12 = "case %s: memcpy(&g%sInst.%s, valPtr, sizeof(%s));\n\t"
    strTemp21 = "case %s: memcpy(valPtr, &g%sInst[instId].%s, sizeof(%s));\n\t"
    strTemp22 = "case %s: memcpy(&g%sInst[instId].%s, valPtr, sizeof(%s));\n\t"
    for i, memItem in enumerate(objitem.MemberList):
        dict_uobj_src["MEMSIZEINFO"] += 'case %s: return sizeof(%s);\n\t' % (1+i, memItem.Type)
        dict_uobj_src["MEMVAL_SET_INFO"] += strTemp11 % (1+i, objitem.Name, memItem.Name, memItem.Type)
        dict_uobj_src["MEMVAL_GET_INFO"] += strTemp12 % (1+i, objitem.Name, memItem.Name, memItem.Type)

    strTemp11 = "TP_STATUS {0}_Get_{1}({2} *valPtr)\n{{\n\treturn _{0}_GetValue(0, {3}, valPtr, sizeof({2}));\n}}\r\n"
    strTemp11 = "TP_STATUS {0}_Get_{1}({2} *valPtr)\n{{\n\treturn _{0}_GetValue(0, {3}, valPtr, sizeof({2}));\n}}\r\n"
    strTemp12 = "TP_STATUS {0}_Set_{1}({2} *valPtr)\n{{\n\treturn _{0}_SetValue(0, {3}, valPtr, sizeof({2});\n}}\r\n"
    strTemp21 = "TP_STATUS {0}_Get_{1}(U32 instId, {2} *valuePtr)\n{{\n\treturn _{0}_GetValue(instId, {3}, valPtr, sizeof({2}));\n}}\r\n"
    strTemp22 = "TP_STATUS {0}_Set_{1}(U32 instId, {2} *valuePtr)\n{{\n\treturn _{0}_SetValue(instId, {3}, valPtr, sizeof({2});\n}}\r\n"
    dict_uobj_src["MEM_GETTER_IMP"] = ""
    dict_uobj_src["MEM_SETTER_IMP"] = ""

    for i, memItem in enumerate(objitem.MemberList):
        if(objitem.InstCnt == 1):
            dict_uobj_src["MEM_GETTER_IMP"] += strTemp11.format(objitem.Name, memItem.Name, memItem.Type, i)
            dict_uobj_src["MEM_SETTER_IMP"] += strTemp12.format(objitem.Name, memItem.Name, memItem.Type, i)
        else:
            dict_uobj_src["MEM_GETTER_IMP"] += strTemp21.format(objitem.Name, memItem.Name, memItem.Type, i)
            dict_uobj_src["MEM_SETTER_IMP"] += strTemp22.format(objitem.Name, memItem.Name, memItem.Type, i)

    if(objitem.InstCnt == 1):
        dict_uobj_src["INSTID_PARA1"] = ""
        dict_uobj_src["INSTID_PARA2"] = ""
    else:
        dict_uobj_src["INSTID_PARA1"] = "U32 instId,"
        dict_uobj_src["INSTID_PARA2"] = "[instId]"

    # Uav Object 源文件生成处理
    outfile = codecs.open('../uavobj/uobj_%s.c'%objitem.Name.lower(), 'w')
    txt = temp_uobj_src.safe_substitute(dict_uobj_src)
    outfile.write(txt)
    outfile.close()

# uavdefine 模板处理结束
############################################################


############################################################
# statuscode 模板处理开始
dict_statuscode_inc = dict()
statusItems = doc_statuscode.getElementsByTagName("Code")
dict_statuscode_inc["STATUS_DEFINE"] = ""
for i, objitem in enumerate(statusItems):
    dict_statuscode_inc["STATUS_DEFINE"] += ('\tTP_%s ' % objitem.getAttribute("name")).ljust(30)
    dict_statuscode_inc["STATUS_DEFINE"] += ('=%d,'% i).ljust(6)
    dict_statuscode_inc["STATUS_DEFINE"] += '/*%s*/\n'% (objitem.getAttribute("note"))

outfile = codecs.open('../uavobj/statuscode.h', 'w', 'utf-8')
txt = temp_statuscode_inc.safe_substitute(dict_statuscode_inc)
outfile.write(txt.decode('utf-8'))
outfile.close()
# statuscode 模板处理结束
############################################################


############################################################
# modules 模板处理开始
modInfoList = []
modItems = doc_modules.getElementsByTagName("Module")
for i, item in enumerate(modItems):
    modInfo = ModuleInfo
    modInfo.Name = item.getAttribute("Name")
    modInfo.Priority = item.getAttribute("Priority")
    modInfo.StackSize = item.getAttribute("StackSize")
    modInfo.MsgQue = item.getAttribute("MsgQue")
    modInfo.Desc = item.getAttribute("Desc")
    modInfoList.append(modInfo)

# 至此所有Module对象解析完毕，待处理

# modules 模板处理结束
############################################################