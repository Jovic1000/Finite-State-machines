workspace "FSMTestEnv"
	configurations { "Debug", "Release" }

	project "FSMTestEnv"
		kind "ConsoleApp"
		language "C++"
		targetdir "bin/%{cfg.buildcfg}"
		files { "%{prj.name}/**.cpp","%{prj.name}/**.h" }
		includedirs { "%{prj.name}" }
		debugdir "assets"
		links {}
		libdirs {}

		vpaths { 
			["./Dependencies/*"] = {"%{prj.name}/[Dd]eps/**"},
			["./Headers"] = {"%{prj.name}/**.h","%{prj.name}/**.hpp"},
			["./Source"] = {"%{prj.name}/**.cpp"}
		}

		filter "configurations:Debug"
			symbols "On"
			defines { "_DEBUG" }

		filter "configurations:Release"
			symbols "Off"
			defines { "NDEBUG" }

		filter "system:Windows"
				defines { "_WIN" }

		filter {}


newaction {
    trigger     = "clean",
    description = "Clean all generated build files except the assets folder and premake5.lua",
    execute     = function ()
        print("Cleaning generated build files...")
        local folders = { "bin", "build", "obj", ".codelite", ".cache" }
        for _, folder in ipairs(folders) do
            if os.isdir(folder) then
                print("Removing folder: " .. folder)
                local files = os.matchfiles(folder .. "/**")
                for _, f in ipairs(files) do
                    if os.isfile(f) then
                        os.remove(f)
                    elseif os.isdir(f) then
                        os.rmdir(f)
                    end
                end
                os.rmdir(folder)
            end
        end
        print("Clean done. Assets folder and premake5.lua remain untouched.")
        os.remove("*.project")
        os.remove("*.workspace")
        os.remove("*.sln")
        os.remove("Makefile")        
        os.remove("*.mk")
        os.remove("compile_commands.json")
    end
}

