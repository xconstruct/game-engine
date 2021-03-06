-- Package Make provides a simple build system for objects containing components.
local Make = {}

-- Make returns a new object consisting of the mentioned components in the
-- component table.
function Make.newMake(components)
	local object = {}
	for name, class in pairs(components) do
		if not class then
			error("Component '"..name.."' not found!", 2)
		end
		if type(name) == "number" then
			name = class.type or name
		end
		if not class.new then
			error("Component '"..name.."' cannot be created!", 2)
		end

		local component = class.new()
		component.parent = object
		object.comp = object.comp or {}
		object.comp[name] = component
	end
	return object
end

return Make
