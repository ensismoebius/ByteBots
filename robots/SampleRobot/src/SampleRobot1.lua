-- SampleRobot.lua
function initialize()
    print("Lua: SampleRobot initialized")
end

function performAction()
    print("Lua: SampleRobot performing action")
end

function displayInfo()
    print("Lua: SampleRobot information")
end


function script1_logic()
    -- Your script logic here
    print("Executing script2 logic")
    return true
end


-- This is a Lua script sample

-- Define a variable
myVar = 123

-- Define a function
function greet(name)
    print("Hello, " .. name .. "!")
end

-- Call the function
greet("John")

-- Perform a simple calculation
result = 2 * myVar + 7

-- Print the result
print("Result: " .. result)
